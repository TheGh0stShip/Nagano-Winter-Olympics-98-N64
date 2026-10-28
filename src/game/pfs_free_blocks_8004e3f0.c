typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Pfs {
    s32 status;
    unsigned char pad4[0x5C];
    s32 inodeStartPage;
    u8 banks;
} Pfs;

typedef struct Inode {
    u16 page[128];
} Inode;

extern s32 func_80054C60(Pfs *pfs);
extern s32 func_80054D5C(Pfs *pfs, Inode *inode, s32 flag, u8 bank);

s32 func_8004E3F0(Pfs *pfs, s32 *bytesNotUsed) {
    s32 index;
    s32 pages = 0;
    Inode inode;
    s32 result = 0;
    u8 bank;
    s32 offset;

    if ((pfs->status & 1) == 0) {
        return 5;
    }
    if (func_80054C60(pfs) == 2) {
        return 2;
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        result = func_80054D5C(pfs, &inode, 0, bank);
        if (result != 0) {
            return result;
        }
        offset = bank > 0 ? 1 : pfs->inodeStartPage;
        for (index = offset; index < 128; index++) {
            if (inode.page[index] == 3) {
                pages++;
            }
        }
    }
    *bytesNotUsed = pages * 8 * 32;
    return 0;
}
