typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x1A];
    unsigned char first;
    unsigned char second;
    unsigned char pad23;
    unsigned char intensity;
    unsigned char pad25[0x27];
    unsigned short active_value;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

extern void func_8004B3E0(void);
extern void func_8004B94C(void);

void func_8004D2E0(void) {
    D_80179924->first = *D_80179920;
    D_80179924->second = *++D_80179920;
    ++D_80179920;

    if (D_80179924->second == 0) {
        D_80179924->intensity = 0;
    } else {
        D_80179924->intensity =
            (D_80179924->first * D_80179924->second) >> 7;
        if (D_80179924->intensity == 0) {
            D_80179924->intensity = 1;
        }
    }
    D_80179924->flags |= 1;
    if (D_80179924->active_value != 0) {
        func_8004B94C();
    }
    if (D_80179924->flags & 1) {
        func_8004B3E0();
    }
}
