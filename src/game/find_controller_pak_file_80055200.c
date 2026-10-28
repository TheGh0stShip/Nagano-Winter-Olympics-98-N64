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
typedef struct Directory {
    u32 gameCode; u16 companyCode; InodeUnit startPage; u8 status;
    signed char reserved; u16 dataSum; u8 extension[4]; u8 name[16];
} Directory;

extern s32 func_80054C60(Pfs *pfs);
extern s32 func_8005F480(void *queue, s32 channel, u16 address, u8 *buffer);

s32 func_80055200(Pfs *pfs, u16 companyCode, u32 gameCode,
                  u8 *gameName, u8 *extension, s32 *fileNo) {
    s32 directoryIndex;
    int characterIndex;
    Directory directory;
    s32 result = 0;
    int mismatch;

    if (func_80054C60(pfs) == 2) {
        return 2;
    }
    for (directoryIndex = 0; directoryIndex < pfs->dirSize; directoryIndex++) {
        result = func_8005F480(pfs->queue, pfs->channel,
                               pfs->dirTable + directoryIndex, (u8 *)&directory);
        if (result != 0) {
            return result;
        }
        if (directory.companyCode == companyCode && directory.gameCode == gameCode) {
            mismatch = 0;
            if (gameName != (u8 *)0) {
                for (characterIndex = 0; characterIndex < 16; characterIndex++) {
                    if (directory.name[characterIndex] != gameName[characterIndex]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (extension != (u8 *)0 && !mismatch) {
                for (characterIndex = 0; characterIndex < 4; characterIndex++) {
                    if (directory.extension[characterIndex] != extension[characterIndex]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (!mismatch) {
                *fileNo = directoryIndex;
                return result;
            }
        }
    }
    *fileNo = -1;
    return 5;
}
