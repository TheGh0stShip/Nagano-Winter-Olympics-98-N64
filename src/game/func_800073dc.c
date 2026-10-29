extern unsigned char D_8006C3D0;
extern unsigned char D_80063500;
extern int D_80131680;
extern unsigned char *D_80126BF0;
extern unsigned char D_801AA600[];
extern unsigned char D_80063990[];
extern unsigned char D_80063948[];
extern unsigned char D_80063958[];
extern unsigned char D_80063718[];
extern unsigned char D_80063698[];
extern unsigned char D_800637C0[];
extern unsigned char D_80063878[];
extern void func_80003870(unsigned char *dst, unsigned char *src, int size);
extern void func_8000C150(void);
extern void func_8000C170(void);
extern void func_8000C190(void *);
extern void func_80007E5C(void);
extern void func_80007F50(void);
extern void func_80006CBC(short level);
extern void func_80006BA8(short level);
extern void func_80006DC8(short level);
extern void func_80006F24(short level);
extern void func_8001B03C(unsigned char *);
extern void func_80006080(unsigned char *, int, void *);
extern void func_80007094(unsigned char, unsigned char *);

int func_800073DC(short level, unsigned char *list) {
    static unsigned char D_8006C3DC = 0;
    static unsigned short D_8006C3E0 = 0;
    unsigned char i;
    unsigned char result;

    unsigned char *record;
    unsigned char pad[16];

    if (D_8006C3DC == 0) {
        D_80131680 = 0;
        func_80007E5C();
        func_80003870(D_80126BF0 + 0x977E0, D_801AA600, 0x3B800);
        func_8000C150();
        func_8000C170();
        func_80007F50();
        D_8006C3DC = 1;
        D_8006C3E0 = 0;
    } else if (D_8006C3DC == 1) {
        func_80006CBC(level);
        D_8006C3DC = 2;
    } else if (D_8006C3DC == 2) {
        record = D_80126BF0 + 0x7F898;
        for (i = 0; i < 2; i++, record += 0x148) {
            if (*(int *)(record + 0x140) != 0) {
                func_8001B03C(record);
            }
        }
        func_8000C150();
        func_80006080(&result, 1, D_80063948);
        func_80006080(&result, 7, D_80063958);
        func_80006BA8(level);
        if (level == 4) {
            func_8000C190(D_80063698);
        }
        D_8006C3DC = 3;
    } else if (D_8006C3DC == 3) {
        func_80006080(&result, 0x10, D_80063718);
        func_80006080(&result, 0x14, D_80063990);
        func_80006DC8(level);
        func_80006F24(level);
        D_8006C3DC = 4;
    } else if (D_8006C3DC == 4) {
        if (D_80063500 == 0 && level == 5) {
            func_8000C190(D_800637C0);
        }
        if (D_80063500 == 0 && (level == 7 || level == 8)) {
            func_8000C190(D_80063878);
        }
        D_8006C3DC = 5;
    } else if (D_8006C3DC == 5) {
        D_80131680 = *(int *)(D_80126BF0 + 0x7C8E8);
        func_80007094(level, list);
        D_8006C3DC = 10;
    } else if (D_8006C3DC == 10) {
        if (D_8006C3E0++ >= 0x24) {
            D_8006C3DC = 6;
            D_8006C3E0 = 0;
        }
    } else if (D_8006C3DC == 6) {
        if (D_80126BF0[0x977EC] == 2 || D_80126BF0[0x977EC] == 3 ||
            (D_80126BF0[0x977F1] != 2 && level == 0) || (D_80126BF0[0x977F1] != 2 && level == 5)) {
            if (D_8006C3E0++ >= 0xB) {
                D_8006C3DC = 0;
                D_8006C3D0 = 0;
                D_8006C3E0 = 0;
                return 1;
            }
        } else {
            D_8006C3DC = 0;
            D_8006C3D0 = 0;
            return 1;
        }
    }
    D_8006C3D0 = 1;
    return 0;
}
