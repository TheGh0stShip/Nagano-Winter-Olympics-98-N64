typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef int s32;
typedef struct Pfs { s32 status; void *queue; s32 channel; u8 id[32]; u8 label[32]; s32 version; s32 dirSize; s32 inodeTable; s32 minodeTable; s32 dirTable; s32 inodeStartPage; u8 banks; u8 activeBank; } Pfs;
typedef union InodeUnit { struct { u8 bank; u8 page; } inode; u16 page; } InodeUnit;
typedef struct Inode { InodeUnit pages[128]; } Inode;
typedef struct Directory { u32 gameCode; u16 companyCode; InodeUnit startPage; u8 status; signed char reserved; u16 dataSum; u8 extension[4]; u8 name[16]; } Directory;
extern s32 func_80055200(Pfs *, u16, u32, u8 *, u8 *, s32 *);
extern s32 func_8004E3F0(Pfs *, s32 *); extern s32 func_80054D5C(Pfs *, Inode *, u8, u8);
extern s32 func_800538F4(Pfs *, Inode *, int, int *, u8, int *, int *);
extern s32 func_8005DE60(void *, s32, u16, u8 *, s32);
extern s32 func_80054C60(Pfs *);

s32 func_80053470(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName,
                  u8 *extension, int byteCount, s32 *fileNo) {
    int startPage; int allocated; int lastPage; int oldLastPage = 0; int index;
    s32 result = 0; int pageCount; Inode inode; Inode backupInode;
    Directory directory; u8 bank; u8 oldBank = 0; int firstTime = 0;
    s32 freeBytes; InodeUnit firstPage;
    if (companyCode == 0 || gameCode == 0) return 5;
    pageCount = (byteCount + 255) / 256;
    if ((pfs->status & 1) == 0) return 5;
    if (func_80054C60(pfs) == 2) return 2;
    result = func_80055200(pfs, companyCode, gameCode, gameName, extension, fileNo);
    if (result != 0 && result != 5) return result;
    if (*fileNo != -1) return 9;
    result = func_8004E3F0(pfs, &freeBytes);
    if (byteCount > freeBytes) return 7;
    if (pageCount != 0) {
        result = func_80055200(pfs, 0, 0, (u8 *)0, (u8 *)0, fileNo);
        if (result != 0 && result != 5) return result;
        if (*fileNo == -1) return 8;
        for (bank = 0; bank < pfs->banks; bank++) {
            result = func_80054D5C(pfs, &inode, 0, bank); if (result != 0) return result;
            result = func_800538F4(pfs, &inode, pageCount, &startPage, bank, &allocated, &lastPage); if (result != 0) return result;
            if (startPage != -1) {
                if (firstTime == 0) { firstPage.inode.page = startPage; firstPage.inode.bank = bank; }
                else {
                    backupInode.pages[oldLastPage].inode.bank = bank;
                    backupInode.pages[oldLastPage].inode.page = startPage;
                    result = func_80054D5C(pfs, &backupInode, 1, oldBank); if (result != 0) return result;
                }
                for (index = 0; index < 128; index++) backupInode.pages[index].page = inode.pages[index].page;
                oldLastPage = lastPage; oldBank = bank; firstTime++;
                if (pageCount > allocated) pageCount = pageCount - allocated;
                else { pageCount = 0; break; }
            }
        }
        if (pageCount > 0 || startPage == -1) return 3;
        backupInode.pages[oldLastPage].inode.bank = bank;
        backupInode.pages[oldLastPage].inode.page = startPage;
        result = func_80054D5C(pfs, &backupInode, 1, oldBank);
        if (result != 0) return result;
        directory.startPage = firstPage;
        directory.companyCode = companyCode;
        directory.gameCode = gameCode;
        directory.dataSum = 0;
        for (index = 0; index < 16; index++) {
            directory.name[index] = *gameName;
            gameName++;
        }
        for (index = 0; index < 4; index++) {
            directory.extension[index] = *extension;
            extension++;
        }
        result = func_8005DE60(pfs->queue, pfs->channel, pfs->dirTable + *fileNo, (u8 *)&directory, 0);
        if (result != 0) return result;
        return result;
    }
    return 5;
}
