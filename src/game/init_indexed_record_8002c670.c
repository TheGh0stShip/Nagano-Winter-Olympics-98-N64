typedef struct Record {
    short flag;
    short active;
    unsigned char pad4[8];
    float start;
    unsigned char pad10[4];
    float end;
    unsigned char pad18[0x110];
    int value;
    unsigned char pad12C[0xC];
} Record;

extern unsigned char *D_80126BF0;
extern int D_80071D4C[];

void func_8002C670(unsigned short kind, short index) {
    Record *record = (Record *)(D_80126BF0 + 0x83EF8) + index;

    record->active = 1;
    record->value = D_80071D4C[kind];
    record->flag = 0;
    record->start = -300.0f;
    record->end = 300.0f;
}
