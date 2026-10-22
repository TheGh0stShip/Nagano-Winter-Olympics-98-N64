typedef struct RuntimeRecord {
    unsigned char pad0[0x68];
    int left;
    int bottom;
    int right;
    int top;
} RuntimeRecord;

extern unsigned char *D_80126BF0;

void func_8001DE70(int index, int width, int height) {
    RuntimeRecord *record;

    record = (RuntimeRecord *)(D_80126BF0 + 0x7FB28) + index;
    record->left = (0x140 - width) / 2;
    record->right = (width + 0x140) / 2;
    record->top = (height + 0xF0) / 2;
    record->bottom = (0xF0 - height) / 2;
}
