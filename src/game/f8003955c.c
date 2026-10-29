typedef struct RuntimeRecord {
    unsigned short kind;
    unsigned char pad2[0xA];
    float x;
    float y;
    float z;
    unsigned char pad18[0x130];
} RuntimeRecord;

typedef struct OffsetEntry {
    float x;
    float y;
    int pad8;
} OffsetEntry;

extern unsigned char *D_80126BF0;
extern OffsetEntry *D_80072FF4[];
extern float D_801381F4;
extern unsigned char D_801381F1;

extern int func_8003B5D0(int id);
extern RuntimeRecord *func_8003EC10(int index, float x, float y, unsigned short kind);
extern int func_8003BAD0(int id, int arg1);
extern int func_8003C498(int handle, signed char arg1, int arg2, int arg3);

void func_8003955C(void) {
    int base;
    int i;
    int index;
    OffsetEntry *table;
    RuntimeRecord *record;

    index = func_8003B5D0(25);
    func_8003EC10(index++, 0, D_801381F4 + -79.5, 1);
    table = D_80072FF4[(D_80126BF0 + 0x90000)[0x77EC]];
    for (i = 0; i < D_801381F1; i++) {
        record = func_8003EC10(index, table[i].x, table[i].y + D_801381F4, 1);
        record->x = table[i].x;
        index++;
    }
    base = func_8003BAD0(index, 0);
    if ((D_80126BF0 + 0x90000)[0x77F1] != 21) {
        func_8003C498(base, 0, 5, 0);
    }
}
