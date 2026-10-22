typedef struct FlagRecord {
    unsigned char pad[0x3C];
} FlagRecord;

extern unsigned char *D_80126BF0;

void func_80013558(int index) {
    *(unsigned short *)(D_80126BF0 + 0x7D23C + index * sizeof(FlagRecord)) = 1;
}
