typedef struct Record {
    short flag;
    unsigned char pad2[0xE];
    float offset;
    unsigned char pad14[0x134];
} Record;

extern unsigned char *D_80126BF0;

void func_8003A148(int start) {
    int i;
    Record *rec;

    for (i = start; i < 0x57; i++) {
        rec = (Record *)(D_80126BF0 + 0x8B2C0) + i;
        rec->flag = 0;
        rec->offset += 240.0f;
    }
}
