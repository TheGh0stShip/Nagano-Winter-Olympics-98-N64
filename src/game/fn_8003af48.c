typedef struct Record {
    unsigned char pad0[0x10];
    unsigned char first;
    unsigned char second;
    unsigned char pad12[0x1A];
} Record;

extern Record D_80137DF8[];
extern unsigned char D_80138214;
extern int func_8003AEF4(int start);
extern void func_8003EA20(int index);

int func_8003AF48(int start, int index) {
    Record *rec;
    unsigned char v;
    int pad[1];

    start = func_8003AEF4(start);
    rec = &D_80137DF8[index];
    if (rec->second != 0) {
        func_8003EA20(start);
        start++;
    }
    if (D_80138214 >= 4) {
        v = rec->first;
        if (v > 0 && v < 4) {
            func_8003EA20(start);
            start++;
        }
        if (v >= 4 && v < 17) {
            func_8003EA20(start);
            start++;
            func_8003EA20(start);
            start++;
        }
    }
    return start;
}
