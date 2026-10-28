typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct Pfs { s32 status; void *queue; s32 channel; u8 id[32]; u8 label[32]; s32 version; s32 dirSize; s32 inodeTable; s32 minodeTable; s32 dirTable; s32 inodeStartPage; u8 banks; u8 activeBank; } Pfs;
typedef union InodeUnit { struct { u8 bank; u8 page; } inode; u16 page; } InodeUnit;
typedef struct Inode { InodeUnit pages[128]; } Inode;
static s32 func_80053B58(Pfs *pfs, int page, u8 *data, u8 bank);
extern s32 func_8005507C(Pfs *); extern s32 func_8005DE60(void *, s32, u16, u8 *, s32);

s32 func_800538F4(Pfs *pfs, Inode *inode, int pageCount, int *firstPage,
                  u8 bank, int *allocated, int *lastPage) {
    int index; int startPage; int oldPage; u8 data[32]; int byteIndex;
    s32 result = 0; int offset = bank > 0 ? 1 : pfs->inodeStartPage;
    for (index = offset; index < 128; index++) { if (inode->pages[index].page == 3) break; }
    if (index == 128) { *firstPage = -1; return result; }
    for (byteIndex = 0; byteIndex < 32; byteIndex++) data[byteIndex] = 0;
    startPage = index; *allocated = 1; oldPage = index; index++;
    while (pageCount > *allocated && index < 128) {
        if (inode->pages[index].page == 3) {
            inode->pages[oldPage].inode.bank = bank;
            inode->pages[oldPage].inode.page = index;
            result = func_80053B58(pfs, oldPage, data, bank);
            if (result != 0) return result;
            oldPage = index; (*allocated)++;
        }
        index++;
    }
    *firstPage = startPage;
    if (index == 128 && pageCount > *allocated) { *lastPage = oldPage; return result; }
    inode->pages[oldPage].page = 1;
    result = func_80053B58(pfs, oldPage, data, bank);
    *lastPage = 0;
    return result;
}

static s32 func_80053B58(Pfs *pfs, int page, u8 *data, u8 bank) {
    int index; s32 result;
    result = 0; pfs->activeBank = bank; result = func_8005507C(pfs);
    if (result != 0) return result;
    for (index = 0; index < 8; index++) {
        result = func_8005DE60(pfs->queue, pfs->channel, page * 8 + index, data, 0);
        if (result != 0) break;
    }
    pfs->activeBank = 0; result = func_8005507C(pfs); return result;
}
