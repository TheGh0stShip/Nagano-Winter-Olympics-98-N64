typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef unsigned int u32; typedef int s32;
typedef struct PifRam { u32 words[15]; u32 status; } PifRam;
typedef struct RamFormat { u8 dummy, txsize, rxsize, cmd; u16 address; u8 data[32]; u8 dataCrc; } RamFormat;
typedef struct Pfs { s32 status; void *queue; s32 channel; u8 id[32]; u8 label[32]; s32 version; s32 dirSize; s32 inodeTable; s32 minodeTable; s32 dirTable; s32 inodeStartPage; u8 banks; u8 activeBank; } Pfs;
static PifRam motorStopData[4];
static PifRam motorStartData[4];
static u8 motorStopBuffer[32];
static u8 motorStartBuffer[32];
extern PifRam D_80192EA0; extern u8 D_80192A30;
extern void func_80050A20(void); extern void func_80050A64(void);
extern s32 func_800521B0(s32, void *); extern s32 func_8004E540(void *, void **, s32);
extern u8 func_8005E1E0(u16); extern s32 func_8005DE60(void *, s32, u16, u8 *, s32);
extern s32 func_8005F480(void *, s32, u16, u8 *);
static void func_80053124(int channel, u16 address, u8 *buffer, PifRam *data);

s32 func_80052E50(Pfs *pfs) {
    int i;
    s32 result;
    u8 *pointer;
    RamFormat format;
    pointer = (u8 *)&D_80192EA0;
    func_80050A20();
    D_80192A30 = 3;
    func_800521B0(1, &motorStopData[pfs->channel]);
    func_8004E540(pfs->queue, 0, 1);
    result = func_800521B0(0, &D_80192EA0);
    func_8004E540(pfs->queue, 0, 1);
    pointer = (u8 *)&D_80192EA0;
    if (pfs->channel != 0) {
        for (i = 0; i < pfs->channel; i++) {
            pointer++;
        }
    }
    format = *(RamFormat *)pointer;
    result = ((format.rxsize & 0xC0) >> 4);
    if (result == 0 && format.dataCrc != 0) result = 4;
    func_80050A64();
    return result;
}

s32 func_80052FB8(Pfs *pfs) {
    int i;
    s32 result;
    u8 *pointer;
    RamFormat format;
    pointer = (u8 *)&D_80192EA0;
    func_80050A20();
    D_80192A30 = 3;
    func_800521B0(1, &motorStartData[pfs->channel]);
    func_8004E540(pfs->queue, 0, 1);
    result = func_800521B0(0, &D_80192EA0);
    func_8004E540(pfs->queue, 0, 1);
    pointer = (u8 *)&D_80192EA0;
    if (pfs->channel != 0) {
        for (i = 0; i < pfs->channel; i++) {
            pointer++;
        }
    }
    format = *(RamFormat *)pointer;
    result = ((format.rxsize & 0xC0) >> 4);
    if (result == 0 && format.dataCrc != 0xEB) result = 4;
    func_80050A64();
    return result;
}

static void func_80053124(int channel, u16 address, u8 *buffer, PifRam *data) {
    u8 *pointer;
    RamFormat format;
    int i;
    pointer = (u8 *)data->words;
    for (i = 0; i < 15; i++) data->words[i] = 0;
    data->status = 1;
    format.dummy = 0xFF;
    format.txsize = 35;
    format.rxsize = 1;
    format.cmd = 3;
    format.address = (address << 5) | func_8005E1E0(address);
    format.dataCrc = 0xFF;
    for (i = 0; i < 32; i++) {
        format.data[i] = *buffer;
        buffer++;
    }
    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *pointer++ = 0;
        }
    }
    *(RamFormat *)pointer = format;
    pointer += sizeof(RamFormat);
    pointer[0] = 0xFE;
}

s32 func_800532A0(void *queue, Pfs *pfs, int channel) {
    int i;
    s32 result;
    u8 temporary[32];
    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    pfs->activeBank = 0x80;
    for (i = 0; i < 32; i++) temporary[i] = 0x80;
    result = func_8005DE60(queue, channel, 0x400, temporary, 0);
    if (result == 2) result = func_8005DE60(queue, channel, 0x400, temporary, 0);
    if (result != 0) return result;
    result = func_8005F480(queue, channel, 0x400, temporary);
    if (result == 2) result = 4;
    if (result != 0) return result;
    if (temporary[31] != 0x80) return 11;
    for (i = 0; i < 32; i++) {
        motorStartBuffer[i] = 1;
        motorStopBuffer[i] = 0;
    }
    func_80053124(channel, 0x600, motorStartBuffer, &motorStartData[channel]);
    func_80053124(channel, 0x600, motorStopBuffer, &motorStopData[channel]);
    return 0;
}
