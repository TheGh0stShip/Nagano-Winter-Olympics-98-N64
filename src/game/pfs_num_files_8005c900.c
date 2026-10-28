typedef unsigned char u8;
typedef signed char s8;
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

typedef struct Directory {
    u32 gameCode;
    u16 companyCode;
    InodeUnit startPage;
    u8 status;
    s8 reserved;
    u16 dataSum;
    u8 extension[4];
    u8 name[16];
} Directory;

extern s32 func_80054C60(Pfs *pfs);
extern s32 func_8005507C(Pfs *pfs);
extern s32 func_8005F480(void *queue, s32 channel, s32 address, u8 *data);

s32 func_8005C900(Pfs *pfs, s32 *maxFiles, s32 *filesUsed) {
    s32 index;
    s32 result;
    Directory directory;
    s32 files = 0;

    if ((pfs->status & 1) == 0) return 5;
    if (func_80054C60(pfs) == 2) return 2;
    if (pfs->activeBank != 0) {
        pfs->activeBank = 0;
        result = func_8005507C(pfs);
        if (result != 0) return result;
    }
    for (index = 0; index < pfs->dirSize; index++) {
        result = func_8005F480(pfs->queue, pfs->channel,
                               pfs->dirTable + index, (u8 *)&directory);
        if (result != 0) return result;
        if (directory.companyCode != 0 && directory.gameCode != 0) files++;
    }
    *filesUsed = files;
    *maxFiles = pfs->dirSize;
    return 0;
}
