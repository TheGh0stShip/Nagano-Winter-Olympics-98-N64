extern unsigned char D_8006C3D0;
extern int D_80131680;
extern unsigned char *D_80126BF0;
extern unsigned char D_801AA600[];
extern unsigned char D_80063948[];
extern unsigned char D_80063958[];
extern unsigned char D_80063550[];
extern void func_80003870(unsigned char *dst, unsigned char *src, int size);
extern void func_8000C150(void);
extern void func_8000C170(void);
extern void func_80007E5C(void);
extern void func_80007F50(void);
extern void func_80006CBC(short level);
extern void func_80006BA8(short level);
extern void func_8001B03C(unsigned char *);
extern void func_80006080(unsigned char *, int, void *);
extern void func_80007094(unsigned char, unsigned char *);

int func_80007744(unsigned char level, unsigned char *list) {
    static unsigned char D_8006C3E4 = 0;
    static unsigned char D_80131684;
    unsigned char i;
    unsigned char *record;
    short unused;
    unsigned char result;
    unsigned char items[4];
    unsigned char buffer[24];

    items[0] = list[0];
    items[1] = list[1];
    items[2] = list[2];
    items[3] = list[3];
    if (D_8006C3E4 == 0) {
        D_80131680 = 0;
        func_80007E5C();
        func_80003870(D_80126BF0 + 0x977E0, D_801AA600, 0x3B800);
        func_8000C150();
        func_8000C170();
        func_80007F50();
        D_8006C3E4 = 1;
        D_80131684 = 0;
    } else if (D_8006C3E4 == 1) {
        func_80006CBC(level);
        D_8006C3E4 = 2;
    } else if (D_8006C3E4 == 2) {
        record = D_80126BF0 + 0x7F898;
        for (i = 0; i < 2; i++, record += 0x148) {
            if (*(int *)(record + 0x140) != 0) {
                func_8001B03C(record);
            }
        }
        func_8000C150();
        func_80006080(&result, 1, D_80063948);
        func_80006080(&result, 7, D_80063958);
        if (level == 0) {
            func_80006080(&result, 0xF, D_80063550);
        }
        func_80006BA8(level);
        D_8006C3E4 = 3;
    } else if (D_8006C3E4 == 3) {
        D_8006C3E4 = 4;
    } else if (D_8006C3E4 == 4) {
        D_80131680 = *(int *)(D_80126BF0 + 0x7C8E8);
        func_80007094(12, items);
        D_8006C3E4 = 10;
    } else if (D_8006C3E4 == 10) {
        if (level != 11) {
            if (D_80131684++ >= 0x1F) {
                D_8006C3E4 = 6;
                D_80131684 = 0;
            }
        } else {
            if (D_80131684++ >= 0x33) {
                D_8006C3E4 = 6;
                D_80131684 = 0;
            }
        }
    } else if (D_8006C3E4 == 6) {
        D_8006C3E4 = 0;
        D_8006C3D0 = 0;
        return 1;
    }
    D_8006C3D0 = 1;
    return 0;
}
