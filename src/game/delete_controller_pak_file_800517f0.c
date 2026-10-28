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

s32 func_800517F0(Pfs *pfs, u16 companyCode, u32 gameCode,
                  u8 *gameName, u8 *extension) {
    s32 fileNo;
    int index;
    s32 result;
    Inode inode;
    Directory directory;
    u16 sum = 0;
    InodeUnit lastPage;
    u8 startPage;
    u8 bank;

    if (companyCode == 0 || gameCode == 0) return 5;
    if ((pfs->status & 1) == 0) return 5;
    if (func_80054C60(pfs) == 2) return 2;
    if (pfs->activeBank != 0) {
        pfs->activeBank = 0;
        result = func_8005507C(pfs);
        if (result != 0) return result;
    }
    result = func_80055200(pfs, companyCode, gameCode, gameName, extension, &fileNo);
    if (result != 0) return result;
    if (fileNo == -1) return 5;
    result = func_8005F480(pfs->queue, pfs->channel,
                           pfs->dirTable + fileNo, (u8 *)&directory);
    if (result != 0) return result;
    startPage = directory.startPage.inode.page;
    for (bank = directory.startPage.inode.bank; bank < pfs->banks;) {
        result = func_80054D5C(pfs, &inode, 0, bank);
        if (result != 0) return result;
        result = func_80051AD0(pfs, &inode, startPage, &sum, bank, &lastPage, 1);
        if (result != 0) return result;
        result = func_80054D5C(pfs, &inode, 1, bank);
        if (result != 0) return result;
        if (lastPage.page == 1) break;
        bank = lastPage.inode.bank;
        startPage = lastPage.inode.page;
    }
    if (bank >= pfs->banks) return 3;
    directory.gameCode = 0;
    directory.companyCode = 0;
    directory.startPage.page = 0;
    directory.dataSum = 0;
    for (index = 0; index < 16; index++) directory.name[index] = 0;
    for (index = 0; index < 4; index++) directory.extension[index] = 0;
    directory.status = 0;
    result = func_8005DE60(pfs->queue, pfs->channel,
                           pfs->dirTable + fileNo, (u8 *)&directory, 0);
    return result;
}
