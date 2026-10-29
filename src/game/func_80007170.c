extern unsigned char D_8006C3D0;
extern int D_80131680;
extern unsigned char *D_80126BF0;
extern unsigned char D_801AA600[];
extern unsigned char D_80063990[];
extern unsigned char D_80063948[];
extern unsigned char D_80063958[];
extern unsigned char D_80063718[];
extern void func_80003870(unsigned char *dst, unsigned char *src, int size);
extern void func_8000C150(void);
extern void func_8000C170(void);
extern void func_80007E5C(void);
extern void func_80007F50(void);
extern void func_80006CBC(short level);
extern void func_80006BA8(short level);
extern void func_80006DC8(short level);
extern void func_80006F24(short level);
extern void func_8001B03C(unsigned char *);
extern void func_80006080(unsigned char *, int, void *);

int func_80007170(short level) {
    static unsigned char D_8006C3D4 = 0;
    static unsigned char D_8006C3D8 = 0;
    unsigned char i;
    unsigned char result;
    unsigned char list[30];
    unsigned char item;
    unsigned char *record;

    if (D_8006C3D4 == 0) {
        D_80131680 = 0;
        func_80007E5C();
        func_80003870(D_80126BF0 + 0x977E0, D_801AA600, 0x3B800);
        func_8000C150();
        func_8000C170();
        func_80007F50();
        D_8006C3D8 = 0;
        func_80006CBC(level);
        D_8006C3D4 = 1;
    } else if (D_8006C3D4 == 1) {
        if (D_8006C3D8++ >= 6) {
            D_8006C3D4 = 2;
            D_8006C3D8 = 0;
        }
    } else if (D_8006C3D4 == 2) {
        record = D_80126BF0 + 0x7F898;
        for (i = 0; i < 2; i++, record += 0x148) {
            if (*(int *)(record + 0x140) != 0) {
                func_8001B03C(record);
            }
        }
        func_8000C150();
        func_80006BA8(level);
        func_80006080(&result, 0x14, D_80063990);
        D_8006C3D4 = 3;
    } else if (D_8006C3D4 == 3) {
        func_80006080(&result, 1, D_80063948);
        func_80006080(&result, 7, D_80063958);
        func_80006080(&result, 0x10, D_80063718);
        func_80006F24(level);
        func_80006DC8(level);
        D_8006C3D4 = 4;
    } else if (D_8006C3D4 == 4) {
        list[0] = item;
        list[1] = item;
        list[2] = 0xFF;
        D_80131680 = *(int *)(D_80126BF0 + 0x7C8E8);
        D_8006C3D4 = 6;
        D_8006C3D8 = 0;
    } else if (D_8006C3D4 == 6) {
        if (D_8006C3D8++ >= 0x15) {
            D_8006C3D4 = 0;
            D_8006C3D0 = 0;
            D_8006C3D8 = 0;
            return 1;
        }
    }
    D_8006C3D0 = 1;
    return 0;
}
