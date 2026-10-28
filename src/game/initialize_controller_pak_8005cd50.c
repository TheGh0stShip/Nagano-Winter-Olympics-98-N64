typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
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

typedef struct PackId {
    u32 repaired;
    u32 random;
    u64 serialMid;
    u64 serialLow;
    u16 deviceId;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 invertedChecksum;
} PackId;

extern void func_80050A20(void);
extern void func_80050A64(void);
extern s32 func_8005CFC0(void *queue, s32 channel);
extern s32 func_8005507C(Pfs *pfs);
extern void func_800543EC(u16 *words, u16 *checksum, u16 *invertedChecksum);
extern s32 func_8005486C(Pfs *pfs, PackId *id);
extern s32 func_80054454(Pfs *pfs, PackId *badId, PackId *newId);
extern s32 func_8005F480(void *queue, s32 channel, u16 address, u8 *buffer);
extern s32 func_8005D0D0(Pfs *pfs);

s32 func_8005CD50(void *queue, Pfs *pfs, int channel) {
    int index;
    s32 result = 0;
    u16 checksum;
    u16 invertedChecksum;
    u8 data[32];
    PackId *id;
    PackId repairedId;

    func_80050A20();
    result = func_8005CFC0(queue, channel);
    func_80050A64();
    if (result != 0) {
        return result;
    }
    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    pfs->activeBank = 0;
    result = func_8005507C(pfs);
    if (result != 0) {
        return result;
    }
    func_800543EC((u16 *)data, &checksum, &invertedChecksum);
    id = (PackId *)data;
    if (id->checksum != checksum || id->invertedChecksum != invertedChecksum) {
        result = func_8005486C(pfs, id);
        if (result != 0) {
            return result;
        }
        if (result != 0) {
            return result;
        }
    }
    if ((id->deviceId & 1) == 0) {
        result = func_80054454(pfs, id, &repairedId);
        if (result != 0) {
            return result;
        }
        id = &repairedId;
        if ((id->deviceId & 1) == 0) {
            return 11;
        }
    }
    for (index = 0; index < 32; index++) {
        pfs->id[index] = ((u8 *)id)[index];
    }
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inodeStartPage = 1 + 2 + 2 * pfs->banks;
    pfs->dirSize = 2 * 8;
    pfs->inodeTable = 1 * 8;
    pfs->minodeTable = (1 + pfs->banks) * 8;
    pfs->dirTable = pfs->minodeTable + pfs->banks * 8;
    result = func_8005F480(pfs->queue, pfs->channel, 7, pfs->label);
    if (result != 0) {
        return result;
    }
    result = func_8005D0D0(pfs);
    pfs->status |= 1;
    return result;
}
