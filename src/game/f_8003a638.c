typedef struct Slot {
    unsigned char pad0[9];
    unsigned char iconA;
    unsigned char pad0A[8];
    unsigned char iconB;
    unsigned char pad13[0x19];
} Slot;

typedef struct SlotF {
    unsigned char pad0[0xC];
    float amount;
} SlotF;

extern unsigned char *D_80126BF0;
extern unsigned char D_80138214;
extern Slot D_80137DF8[];
extern unsigned int D_800725B0[];
extern unsigned int D_80072B64[];
extern unsigned char D_06005DB8[];
extern int func_80038FC4(void);
extern void func_800389B4(int id);
extern int func_80036FC4(void);
extern void func_80039004(int id, float x, float y, int size, void *data, int kind);
extern void *func_800375F0(int index, unsigned short flags, float x, float y, float first, float second);

int func_8003A638(int id, int n) {
    int mode;
    Slot *slot;
    unsigned short flags;
    float amount;
    int skip;

    mode = func_80038FC4();
    func_800389B4(id);
    id++;
    func_800389B4(id);
    id++;
    flags = func_80036FC4();
    slot = &D_80137DF8[n];
    amount = ((SlotF *)slot)->amount;
    skip = 0;
    if (D_80126BF0[0x977F1] == 0x15 && D_80138214 == 2 && amount == 0) {
        skip = 1;
    }
    if (amount < 0) {
        skip = 1;
    }
    if (skip == 0) {
        func_800389B4(id);
        func_800375F0(id, flags, 0.0f, (float)(n * 16 - 64), (float)((n & 7) + 8), amount);
    } else {
        func_80039004(id, 0.0f, 0.0f, 0x14, D_06005DB8, mode);
    }
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, (void *)D_800725B0[slot->iconA], 1);
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, (void *)D_80072B64[slot->iconB], 1);
    id++;
    return id;
}
