typedef struct RuntimeData {
    unsigned char pad0[0x977F4];
    unsigned char flagA;
    unsigned char pad977F5[3];
    unsigned char flagB;
} RuntimeData;

extern unsigned char *D_80126BF0;
extern int D_801335C0;
extern short D_801335C6;
extern int D_80136C84;
extern unsigned char D_8006D444;
typedef struct Flags8006D440 {
    unsigned char unk0;
    unsigned char pad1[3];
    unsigned char enabled;
} Flags8006D440;
extern Flags8006D440 D_8006D440;
extern short D_8006D43C;
extern void func_80030E0C(int *arg0);
extern void func_80030E30(void);
extern void func_80030E54(void);
extern int func_80030F70(void);
extern void func_800485AC(int arg0);
extern int func_80007170(int arg0);
extern void func_8000DCC0(void);
extern int func_8000DA60(void);
extern void func_8000DAC0(void);
extern int func_8000E84C(short *arg0);

int func_8000E5C4(void) {
    unsigned char next;

    switch (D_801335C0) {
    case 0:
        next = D_8006D440.enabled + 1;
        D_801335C0 = 10;
        D_80136C84 = 15;
        if (next >= 2) {
            next = 0;
        }
        D_8006D444 = next;
        if (next) {
            func_80030E0C(&D_80136C84);
        } else {
            func_80030E0C(&D_80136C84);
        }
        return 0;
    case 10:
        ((RuntimeData *)D_80126BF0)->flagA = 0;
        ((RuntimeData *)D_80126BF0)->flagB = 0;
        D_801335C0 = 11;
        func_800485AC(1);
        return 0;
    case 11:
        if (D_80136C84 != 0) {
            D_80136C84--;
        }
        if (!func_80007170(0x1C)) {
            return 0;
        }
        D_801335C0 = 12;
        D_801335C6 = 0;
        func_8000DCC0();
        *(unsigned short *)(D_80126BF0 + 0x80000 + 0x3EF8) = 1;
        *(unsigned short *)(D_80126BF0 + 0x80000 + 0x4030) = 1;
        *(unsigned short *)(D_80126BF0 + 0x80000 + 0x4032) = 1;
        *(unsigned short *)(D_80126BF0 + 0x80000 + 0x4168) = 1;
        *(unsigned short *)(D_80126BF0 + 0x80000 + 0x416A) = 1;
        *(unsigned short *)(D_80126BF0 + 0x78000 + 0x7898) = 1;
        *(float *)(D_80126BF0 + 0x78000 + 0x78AC) = 0.0f;
        break;
    case 12:
        if (func_8000DA60()) {
            func_8000DAC0();
        }
        if (func_8000E84C(&D_801335C6)) {
            D_801335C0 = 13;
            func_80030E30();
            func_800485AC(10);
            return 0;
        }
        break;
    case 13:
        if (func_80030F70() == 0) {
            D_801335C0 = 14;
        }
        break;
    case 14:
        return 1;
    case 30:
        next = D_8006D444;
        if (next) {
            func_80030E30();
        } else {
            func_80030E54();
        }
        D_801335C0 = 31;
        break;
    case 31:
        if (func_80030F70() != 2) {
            next = D_8006D444;
            D_8006D43C = 0;
            if (next) {
                return 2;
            }
            return 0xFF;
        }
        break;
    case 50:
        return 2;
    default:
        D_801335C0 = 0;
        break;
    }
    return 0;
}
