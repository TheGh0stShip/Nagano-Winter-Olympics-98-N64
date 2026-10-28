typedef struct StreamState {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x1A];
    unsigned char mode;
    unsigned char enabled;
    unsigned char pad23;
    unsigned char countdown;
    unsigned char pad25[0x27];
    unsigned short first;
    unsigned char pad4E[0x2F];
    unsigned char active;
    unsigned char pad7E[0x1C];
    unsigned short second;
} StreamState;

extern StreamState *D_80179924;
extern void func_8004CB64(void);
extern void func_8004C658(void);
extern void func_8004B274(void);
extern void func_8004B900(void);
extern void func_8004B8BC(void);
extern void func_8004B94C(void);
extern void func_8004B3E0(void);
extern void func_8004B0F4(void);

void func_8004AFD8(void) {
    if (D_80179924->active != 0) {
        func_8004CB64();
    }
    if (D_80179924->second != 0) {
        func_8004C658();
    }
    if (D_80179924->flags & 2) {
        func_8004B274();
    }
    if (D_80179924->enabled != 0) {
        if (D_80179924->mode == 1) {
            func_8004B900();
            return;
        }
    }
    if (D_80179924->countdown != 0) {
        D_80179924->countdown--;
        if (D_80179924->countdown == 0) {
            func_8004B8BC();
            return;
        }
    }
    if (D_80179924->first != 0) {
        func_8004B94C();
    }
    if (D_80179924->flags & 1) {
        func_8004B3E0();
    } else {
        func_8004B0F4();
    }
}
