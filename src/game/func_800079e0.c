extern unsigned char *D_80126BF0;
extern unsigned char D_801AA600[];
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
extern void func_80006748(unsigned char, unsigned char);

int func_800079E0(short level, unsigned char mode, unsigned char *list) {
    static unsigned char D_8006C3E8 = 0;
    unsigned char i;

    if (D_8006C3E8 == 0) {
        func_80007E5C();
        func_80003870(D_80126BF0 + 0x977E0, D_801AA600, 0x3B800);
        func_8000C150();
        func_8000C170();
        func_80007F50();
        D_8006C3E8 = 1;
    } else if (D_8006C3E8 == 1) {
        func_80006CBC(level);
        D_8006C3E8 = 2;
    } else if (D_8006C3E8 == 2) {
        list = D_80126BF0 + 0x7F898;
        for (i = 0; i < 2; i++, list += 0x148) {
            if (*(int *)(list + 0x140) != 0) {
                func_8001B03C(list);
            }
        }
        func_8000C150();
        func_80006BA8(level);
        D_8006C3E8 = 3;
    } else if (D_8006C3E8 == 3) {
        func_80006DC8(level);
        func_80006F24(level);
        D_8006C3E8 = 4;
    } else if (D_8006C3E8 == 4) {
        for (i = 0; i < 3 && *list != 0xFF; i++, list++) {
            func_80006748(mode, *list);
        }
        D_8006C3E8 = 6;
    } else if (D_8006C3E8 == 6) {
        D_8006C3E8 = 0;
        return 1;
    }
    return 0;
}
