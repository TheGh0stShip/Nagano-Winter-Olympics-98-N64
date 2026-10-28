typedef struct StreamRecord {
    unsigned char pad0[0x4E];
    unsigned short rate;
    unsigned short depth;
    unsigned char pad52[2];
    unsigned short shift;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;
extern unsigned short D_80073ADE[];
extern unsigned short D_80073A5A[];

void func_8004BF88(void) {
    unsigned char value;

    D_80179924->rate = D_80073ADE[0 - *D_80179920];
    D_80179920++;
    value = *D_80179920++;
    D_80179924->depth = D_80073A5A[0 - ((value & 0xF0) >> 2)];
    D_80179924->shift = (value & 0xF) << 2;
}
