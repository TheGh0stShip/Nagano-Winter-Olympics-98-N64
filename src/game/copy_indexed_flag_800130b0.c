typedef struct InputRecord {
    unsigned short value;
    unsigned char unused;
    unsigned char index;
} InputRecord;

extern unsigned char *D_80126BF0;

void func_800130B0(InputRecord *input) {
    *(unsigned short *)(D_80126BF0 + 0x7D23C + input->index * 0x3C) = input->value;
}
