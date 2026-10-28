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
extern s32 func_80054D5C(Pfs *pfs, Inode *inode, u8 flag, u8 bank);

s32 func_80052340(Pfs *pfs, u8 *bank, Inode *inode, InodeUnit *page) {
    s32 result;
    if (page->inode.bank != *bank) {
        *bank = page->inode.bank;
        result = func_80054D5C(pfs, inode, 0, *bank);
        if (result != 0) return result;
    }
    *page = inode->pages[page->inode.page];
    if (!(page->page >= pfs->inodeStartPage && page->inode.bank < pfs->banks &&
          page->inode.page > 0 && page->inode.page < 128)) {
        if (page->page == 1) return 5;
        return 3;
    }
    return 0;
}

typedef unsigned int u32;
typedef struct Directory { u32 gameCode; u16 companyCode; InodeUnit startPage; u8 status; signed char reserved; u16 dataSum; u8 extension[4]; u8 name[16]; } Directory;
extern s32 func_80054C60(Pfs *); extern s32 func_8005507C(Pfs *);
extern s32 func_8005F480(void *, s32, u16, u8 *); extern s32 func_8005DE60(void *, s32, u16, u8 *, s32);

s32 func_8005243C(Pfs *pfs, s32 fileNo, u8 flag, int offset, int byteCount, u8 *data) {
    s32 result; Directory directory; Inode inode; InodeUnit currentPage;
    int currentBlock; int blocksLeft; u8 *buffer; u8 bank; u16 block;
    if (fileNo >= pfs->dirSize || fileNo < 0) return 5;
    if (byteCount <= 0 || byteCount % 32 != 0) return 5;
    if (offset < 0 || offset % 32 != 0) return 5;
    if ((pfs->status & 1) == 0) return 5;
    if (func_80054C60(pfs) == 2) return 2;
    if (pfs->activeBank != 0) { pfs->activeBank = 0; result = func_8005507C(pfs); if (result != 0) return result; }
    result = func_8005F480(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&directory);
    if (result != 0) return result;
    if (!(directory.startPage.page >= pfs->inodeStartPage && directory.startPage.inode.bank < pfs->banks && directory.startPage.inode.page > 0 && directory.startPage.inode.page < 128)) {
        if (directory.startPage.page == 1) return 5;
        return 3;
    }
    if (flag == 0 && (directory.status & 2) == 0) return 6;
    bank = 0xFF; currentBlock = offset / 32; currentPage = directory.startPage;
    while (currentBlock >= 8) { result = func_80052340(pfs, &bank, &inode, &currentPage); if (result != 0) return result; currentBlock -= 8; }
    blocksLeft = byteCount / 32; buffer = data;
    while (blocksLeft > 0) {
        if (currentBlock == 8) { result = func_80052340(pfs, &bank, &inode, &currentPage); if (result != 0) return result; currentBlock = 0; }
        if (pfs->activeBank != currentPage.inode.bank) { pfs->activeBank = currentPage.inode.bank; result = func_8005507C(pfs); if (result != 0) return result; }
        block = currentPage.inode.page * 8 + currentBlock;
        if (flag == 0) result = func_8005F480(pfs->queue, pfs->channel, block, buffer);
        else result = func_8005DE60(pfs->queue, pfs->channel, block, buffer, 0);
        if (result != 0) return result;
        buffer += 32;
        currentBlock++;
        blocksLeft--;
    }
    if (flag == 1 && !(directory.status & 2)) {
        directory.status |= 2; pfs->activeBank = 0; result = func_8005507C(pfs); if (result != 0) return result;
        result = func_8005DE60(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&directory, 0);
        if (result != 0) return result;
    }
    return 0;
}
