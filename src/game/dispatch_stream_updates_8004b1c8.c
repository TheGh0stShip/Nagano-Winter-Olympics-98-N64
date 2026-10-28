typedef struct StreamState {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x45];
    unsigned short first;
    unsigned char pad4E[0x2F];
    unsigned char active;
    unsigned char pad7E[0x1C];
    unsigned short second;
} StreamState;

extern StreamState *D_80179924;
extern void func_8004CBFC(void);
extern void func_8004C6D4(void);
extern void func_8004B274(void);
extern void func_8004B94C(void);
extern void func_8004B3E0(void);

void func_8004B1C8(void) {
    if (D_80179924->active != 0) {
        func_8004CBFC();
    }
    if (D_80179924->second != 0) {
        func_8004C6D4();
    }
    if (D_80179924->flags & 2) {
        func_8004B274();
    }
    if (D_80179924->first != 0) {
        func_8004B94C();
    }
    if (D_80179924->flags & 1) {
        func_8004B3E0();
    }
}
