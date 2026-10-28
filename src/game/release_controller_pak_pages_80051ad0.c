typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct Pfs {
    s32 status; void *queue; s32 channel; u8 id[32]; u8 label[32];
    s32 version; s32 dirSize; s32 inodeTable; s32 minodeTable;
    s32 dirTable; s32 inodeStartPage; u8 banks; u8 activeBank;
} Pfs;
typedef union InodeUnit { struct { u8 bank; u8 page; } inode; u16 page; } InodeUnit;
typedef struct Inode { InodeUnit pages[128]; } Inode;
extern s32 func_80051D08(Pfs *pfs, u8 page, u16 *sum, u8 bank);

s32 func_80051AD0(Pfs *pfs, Inode *inode, u8 startPage, u16 *sum,
                  u8 bank, InodeUnit *finalPage, int flag) {
    InodeUnit nextPage;
    InodeUnit oldPage;
    s32 result = 0;
    int offset;

    nextPage = inode->pages[startPage];
    if (nextPage.page != 1) {
        if (nextPage.inode.bank > 0) offset = 1;
        else offset = pfs->inodeStartPage;
    } else {
        if (bank > 0) offset = 1;
        else offset = pfs->inodeStartPage;
    }
    if (nextPage.inode.page < offset && nextPage.page != 1) return 3;
    *finalPage = nextPage;
    if (flag == 1) inode->pages[startPage].page = 3;
    result = func_80051D08(pfs, startPage, sum, bank);
    if (result != 0) return result;
    if (nextPage.page == 1) return 0;
    while (nextPage.page >= pfs->inodeStartPage) {
        oldPage = nextPage;
        nextPage = inode->pages[nextPage.inode.page];
        inode->pages[oldPage.inode.page].page = 3;
        result = func_80051D08(pfs, oldPage.inode.page, sum, bank);
        if (result != 0) return result;
        if (nextPage.inode.bank != bank) break;
    }
    if (nextPage.page >= pfs->inodeStartPage) {
        inode->pages[nextPage.inode.page].page = 3;
    }
    *finalPage = nextPage;
    return 0;
}
