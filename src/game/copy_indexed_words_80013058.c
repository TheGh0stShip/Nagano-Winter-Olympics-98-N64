typedef struct InputRecord {
    unsigned char pad0[3];
    unsigned char index;
    unsigned char pad4[0x24];
    unsigned int first;
    unsigned int second;
} InputRecord;

extern unsigned char *D_80126BF0;

void func_80013058(InputRecord *input) {
    *(unsigned int *)(D_80126BF0 + 0x78000 + input->index * 0x3C + 0x5264) =
        input->first;
    *(unsigned int *)(D_80126BF0 + 0x78000 + input->index * 0x3C + 0x5268) =
        input->second;
}
