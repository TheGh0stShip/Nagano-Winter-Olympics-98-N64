typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct Pfs {
    s32 status; void *queue; s32 channel; u8 id[32]; u8 label[32];
    s32 version; s32 dirSize; s32 inodeTable; s32 minodeTable;
    s32 dirTable; s32 inodeStartPage; u8 banks; u8 activeBank;
} Pfs;
typedef union InodeUnit { struct { u8 bank; u8 page; } inode; u16 page; } InodeUnit;
typedef struct Inode { InodeUnit pages[128]; } Inode;
typedef struct Directory {
    u32 gameCode; u16 companyCode; InodeUnit startPage; u8 status;
    signed char reserved; u16 dataSum; u8 extension[4]; u8 name[16];
} Directory;

extern s32 func_80054C60(Pfs *pfs);
extern s32 func_8005507C(Pfs *pfs);
extern s32 func_80055200(Pfs *, u16, u32, u8 *, u8 *, s32 *);
extern s32 func_8005F480(void *, s32, u16, u8 *);
extern s32 func_80054D5C(Pfs *, Inode *, u8, u8);
extern s32 func_80051AD0(Pfs *, Inode *, u8, u16 *, u8, InodeUnit *, int);
extern s32 func_8005DE60(void *, s32, u16, u8 *, s32);
extern s32 func_8004E3F0(Pfs *, s32 *);
extern s32 func_800538F4(Pfs *, Inode *, int, int *, u8, int *, int *);

s32 func_8004D880(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName,
                  u8 *extension, int byteCount) {
    int startPage;
    s32 result;
    int pageCount;
    Inode inode;
    Inode backupInode;
    Directory directory;
    s32 fileNo;
    int usedPages;
    InodeUnit previous;
    InodeUnit current;
    u16 sum;
    s32 freeBytes;
    int needed;
    u8 bank;
    int allocated;
    int firstTime;
    int linkCount;
    int index;
    InodeUnit lastUnit;
    int lastPage;
    int oldLastPage;
    u8 oldBank;
    u8 startBank;
    int shrinkCount;
    InodeUnit chainPage;
    int minPage;

    result = 0;
    sum = 0;
    firstTime = 0;
    linkCount = 0;
    oldLastPage = 0;
    oldBank = 0;
    startBank = 0;
    shrinkCount = 0;

    if (companyCode == 0 || gameCode == 0) return 5;
    pageCount = (byteCount + 255) / 256;
    if ((pfs->status & 1) == 0) return 5;
    if (func_80054C60(pfs) == 2) return 2;
    result = func_80055200(pfs, companyCode, gameCode, gameName, extension, &fileNo);
    if (result != 0 && result != 5) return result;
    if (fileNo == -1) return 5;
    if (pageCount != 0) {
        if (pfs->activeBank != 0) {
            pfs->activeBank = 0;
            result = func_8005507C(pfs);
            if (result != 0) return result;
        }
        result = func_8005F480(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&directory);
        if (result != 0) return result;
        if (directory.startPage.page < pfs->inodeStartPage) return 3;
        usedPages = 0;
        oldLastPage = startPage = directory.startPage.inode.page;
        bank = directory.startPage.inode.bank;
        while (bank < pfs->banks) {
            result = func_80054D5C(pfs, &inode, 0, bank);
            if (result != 0) return result;
            current = inode.pages[startPage];
            while (current.page >= pfs->inodeStartPage) {
                usedPages++;
                oldLastPage = current.inode.page;
                current = inode.pages[current.inode.page];
                if (current.inode.bank != bank) {
                    bank = current.inode.bank;
                    oldLastPage = startPage = current.inode.page;
                    break;
                }
            }
            if (current.page == 1) {
                usedPages++;
                break;
            }
        }
        startBank = bank;
        if (bank >= pfs->banks) return 3;
        if (pageCount > usedPages) {
            needed = pageCount - usedPages;
            result = func_8004E3F0(pfs, &freeBytes);
            if (needed > freeBytes / 256) return 7;
            oldBank = bank;
            for (index = 0; index < 128; index++) backupInode.pages[index].page = inode.pages[index].page;
            for (bank = 0; bank < pfs->banks; bank++) {
                result = func_80054D5C(pfs, &inode, 0, bank);
                if (result != 0) return result;
                result = func_800538F4(pfs, &inode, needed, &startPage, bank, &allocated, &lastPage);
                if (result != 0) return result;
                if (startPage != -1) {
                    if (firstTime != 0 || startBank != bank) {
                        linkCount++;
                        backupInode.pages[oldLastPage].inode.bank = bank;
                        backupInode.pages[oldLastPage].inode.page = startPage;
                        result = func_80054D5C(pfs, &backupInode, 1, oldBank);
                        if (result != 0) return result;
                    }
                    for (index = 0; index < 128; index++) backupInode.pages[index].page = inode.pages[index].page;
                    if (needed > allocated) {
                        needed = needed - allocated;
                    } else {
                        needed = 0;
                        oldBank = bank;
                        break;
                    }
                    oldLastPage = lastPage;
                    oldBank = bank;
                    firstTime++;
                }
            }
            if (needed > 0 || startPage == -1) return 3;
            if (linkCount == 0) {
                backupInode.pages[oldLastPage].inode.bank = bank;
                backupInode.pages[oldLastPage].inode.page = startPage;
            }
            result = func_80054D5C(pfs, &backupInode, 1, oldBank);
            if (result != 0) return result;
        } else if (pageCount < usedPages) {
            chainPage.page = directory.startPage.page;
            for (bank = directory.startPage.inode.bank; bank < pfs->banks;) {
                result = func_80054D5C(pfs, &inode, 0, bank);
                if (result != 0) return result;
                previous = chainPage;
                current = inode.pages[chainPage.inode.page];
                pageCount--;
                minPage = bank > 0 ? 1 : pfs->inodeStartPage;
                if (current.inode.page < minPage) {
                    if (current.page != 1) return 3;
                }
                while (pageCount > 0 && current.page >= pfs->inodeStartPage) {
                    pageCount--;
                    previous.page = current.page;
                    current = inode.pages[current.inode.page];
                    if (current.inode.bank != bank) {
                        if (pageCount == 1) {
                            inode.pages[previous.inode.page].page = 1;
                            result = func_80054D5C(pfs, &inode, 1, bank);
                            if (result != 0) return result;
                        }
                        shrinkCount++;
                        chainPage.page = current.page;
                        bank = current.inode.bank;
                        result = func_80054D5C(pfs, &inode, 0, bank);
                        if (result != 0) return result;
                        break;
                    }
                }
                if (pageCount == 0) break;
            }
            if (bank >= pfs->banks) return 3;
            if (shrinkCount == 0) inode.pages[previous.inode.page].page = 1;
            else inode.pages[current.inode.page].page = 1;
            if (current.page == 1) {
                inode.pages[previous.inode.page].page = 3;
                result = func_80054D5C(pfs, &inode, 1, bank);
                if (result != 0) return result;
            } else {
            chainPage.page = current.page;
            for (bank = current.inode.bank; bank < pfs->banks;) {
                result = func_80051AD0(pfs, &inode, chainPage.inode.page, &sum, bank, &lastUnit, 0);
                if (result != 0) return result;
                result = func_80054D5C(pfs, &inode, 1, bank);
                if (result != 0) return result;
                if (lastUnit.page == 1) break;
                bank = lastUnit.inode.bank;
                chainPage = lastUnit;
                result = func_80054D5C(pfs, &inode, 0, bank);
                if (result != 0) return result;
            }
            if (bank >= pfs->banks) return 3;
            }
            if (directory.dataSum > sum) directory.dataSum = directory.dataSum - sum;
            else directory.dataSum = sum - directory.dataSum;
            result = func_8005DE60(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&directory, 0);
            if (result != 0) return result;
        }
        return result;
    }
    return 5;
}
