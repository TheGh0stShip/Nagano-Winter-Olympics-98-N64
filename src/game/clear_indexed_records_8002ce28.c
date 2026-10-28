typedef struct Record {
    short flag;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[8];
} Record;

extern unsigned char *D_80126BF0;
extern unsigned char D_801374D0[];

void func_8002CE28(void) {
    unsigned short i;
    Record *record;
    unsigned char index;

    for (i = 0; i < 6; i++) {
        index = D_801374D0[i];
        record = (Record *)(D_80126BF0 + 0x83EF8) + index;
        record->value = 0;
        record->flag = 0;
    }
}
