typedef struct Record {
    unsigned short kind;
    unsigned short state;
    unsigned char pad4[0x128];
    int value;
    unsigned char pad130[8];
} Record;

extern unsigned char *D_80126BF0;
extern void func_80009358(short id, int flag, int arg);

void func_800437A0(short id, int arg1, int value, unsigned short state, unsigned short kind) {
    func_80009358(id, 1, arg1);
    ((Record *)(D_80126BF0 + 0x83EF8))[(unsigned short)id].value = value;
    ((Record *)(D_80126BF0 + 0x83EF8))[(unsigned short)id].state = state;
    ((Record *)(D_80126BF0 + 0x83EF8))[(unsigned short)id].kind = kind;
}
