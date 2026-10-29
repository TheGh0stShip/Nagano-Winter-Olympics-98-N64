typedef struct { unsigned short id; unsigned char pad2[2]; unsigned char type; unsigned char pad5; } E801796A0;
typedef struct {
    int flags;
    unsigned char pad4[2];
    unsigned char dirty;
    unsigned char pad7[0xA2 - 7];
    short a2;
    unsigned short a4;
    signed char a6;
    unsigned char pada7[0xD0 - 0xA7];
} V8018C980;
extern E801796A0 D_801796A0[];
extern V8018C980 *D_80179924;
extern V8018C980 D_8018C980[];
extern int func_800487A4(unsigned char, unsigned char);
extern void func_8004A250(unsigned char);

void func_8004883C(int arg0) {
    E801796A0 *e;
    unsigned char type;
    int i;
    V8018C980 *p;
    int v;

    e = &D_801796A0[arg0];
    type = e->type;
    for (i = 0; i != 16; i++) {
        D_80179924 = &D_8018C980[i];
        if (e->id == (D_80179924->flags & 0x7FFF)) {
            v = func_800487A4(arg0, type);
            switch (type) {
            case 0:
                if (v < -0x9000) v = -0x9000;
                else if (v > 0x9000) v = 0x9000;
                if (D_80179924->a2 != (short)v) {
                    D_80179924->dirty |= 2;
                    D_80179924->a2 = v;
                }
                break;
            case 1:
                if (v < 0x10) v = 0x10;
                else if (v > 0x100) v = 0x100;
                if (D_80179924->a4 != (unsigned short)v) {
                    D_80179924->dirty |= 1;
                    D_80179924->a4 = v;
                }
                break;
            case 2:
                if (v < -0x7F) v = -0x7F;
                else if (v > 0x7F) v = 0x7F;
                if (D_80179924->a6 != (signed char)v) {
                    D_80179924->a6 = v;
                    func_8004A250(i);
                }
                break;
            }
        }
    }
}
