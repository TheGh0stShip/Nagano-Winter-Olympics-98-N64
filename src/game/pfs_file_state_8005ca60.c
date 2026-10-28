typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Pfs {
    s32 status;
    void *queue;
    s32 channel;
    u8 id[32];
    u8 label[32];
    s32 version;
    s32 dirSize;
    s32 inodeTable;
    s32 minodeTable;
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} Pfs;

typedef union InodeUnit {
    struct { u8 bank; u8 page; } inode;
    u16 page;
} InodeUnit;

typedef struct Inode { InodeUnit pages[128]; } Inode;

typedef struct Directory {
    u32 gameCode;
    u16 companyCode;
    InodeUnit startPage;
    u8 status;
    signed char reserved;
    u16 dataSum;
    u8 extension[4];
    u8 name[16];
} Directory;

typedef struct PfsState {
    u32 fileSize;
    u32 gameCode;
    u16 companyCode;
    u8 extension[4];
    u8 name[16];
} PfsState;

extern s32 func_80054C60(Pfs *pfs);
extern s32 func_8005507C(Pfs *pfs);
extern s32 func_8005F480(void *queue, s32 channel, s32 address, u8 *data);
extern s32 func_80054D5C(Pfs *pfs, Inode *inode, s32 flag, u8 bank);

s32 func_8005CA60(Pfs *pfs, s32 fileNo, PfsState *state) {
    s32 result;
    s32 pages;
    Inode inode;
    Directory directory;
    InodeUnit nextPage;
    s32 index;
    u8 bank;
    u8 startPage;

    if (fileNo >= pfs->dirSize || fileNo < 0) {
        return 5;
    }
    if ((pfs->status & 1) == 0) {
        return 5;
    }
    if (func_80054C60(pfs) == 2) {
        return 2;
    }
    if (pfs->activeBank != 0) {
        pfs->activeBank = 0;
        result = func_8005507C(pfs);
        if (result != 0) {
            return result;
        }
    }
    result = func_8005F480(pfs->queue, pfs->channel,
                           pfs->dirTable + fileNo, (u8 *)&directory);
    if (result != 0) {
        return result;
    }
    if (directory.companyCode == 0 || directory.gameCode == 0) {
        return 5;
    }
    if (directory.startPage.page < pfs->inodeStartPage) {
        return 3;
    }

    pages = 0;
    startPage = directory.startPage.inode.page;
    bank = directory.startPage.inode.bank;
    while (bank < pfs->banks) {
        result = func_80054D5C(pfs, &inode, 0, bank);
        if (result != 0) {
            return result;
        }
        nextPage = inode.pages[startPage];
        pages++;
        while (nextPage.page >= pfs->inodeStartPage) {
            pages++;
            nextPage = inode.pages[nextPage.inode.page];
            if (nextPage.inode.bank != bank) {
                bank = nextPage.inode.bank;
                startPage = nextPage.inode.page;
                break;
            }
        }
        if (nextPage.page == 1) {
            break;
        }
    }
    if (nextPage.page != 1) {
        return 3;
    }

    state->fileSize = pages * 256;
    state->companyCode = directory.companyCode;
    state->gameCode = directory.gameCode;
    for (index = 0; index < 16; index++) {
        state->name[index] = directory.name[index];
    }
    for (index = 0; index < 4; index++) {
        state->extension[index] = directory.extension[index];
    }
    return 0;
}
