typedef struct {
    int unk0;
    char pad4;
    unsigned char unk5;
    char pad6[8];
    unsigned char unkE;
    unsigned char unkF;
    char pad10[0xA];
    unsigned short unk1A;
    char pad1C[0xD0 - 0x1C];
} Obj;

typedef struct {
    char data[0x1C];
} Snd;

extern void func_80049E20(void);
extern void func_80049F88(void);
extern void func_8004A4C0(unsigned short);
extern void func_8004A9A4(void);
extern void func_8005FDD0(int, Snd *);
extern int D_8007C910;
extern unsigned short D_8017966A;
extern unsigned char D_8017966C;
extern unsigned char D_8017966D;
extern signed char D_8017966E;
extern unsigned char D_8017966F;
extern unsigned char D_80179671;
extern unsigned char D_80179672;
extern unsigned char D_80179673;
extern unsigned char D_80179674;
extern unsigned char D_80179675;
extern unsigned char D_80179676;
extern unsigned short D_80179678;
extern unsigned char D_8017967A;
extern signed char D_8017967B;
extern unsigned char D_8017967C;
extern unsigned char D_8017967E[];
extern unsigned short D_80179680[];
extern unsigned char D_8017975A;
extern Snd D_80179760[];
extern Obj *D_80179924;
extern Obj D_8018C980[];
extern int D_8018CF30;

void func_8004A5C4(void) {
    int i;

    if (D_8017975A == 2) {
        if ((D_8018CF30 & 0x7FFF) < 0x300U && (D_8018CF30 & 0x7FFF) < 0x468U) {
            D_8017975A = 0;
        }
    }
    if (D_8017966E != 0 && !(D_8017966A & 1)) {
        D_8017966F += D_8017966E;
        if (D_8017966F < 9 || D_8017966F == 0) {
            D_8017966E = 0;
        }
    }
    if (D_80179676 != 0 && D_8017966D == 0 && !(D_8017966A & 3)) {
        D_80179675--;
        if (D_80179675 == 0) {
            D_80179675 = D_80179674;
            D_80179676 -= 4;
            if (D_80179676 < 0x10) {
                func_80049E20();
            }
        }
    }
    if (D_80179673 != 0 && D_8017966D == 0 && !(D_8017966A & 3)) {
        D_80179672--;
        if (D_80179672 == 0) {
            D_80179672 = D_80179671;
            D_80179673 -= 4;
            if (D_80179673 < 0x10) {
                func_80049F88();
            }
        }
    }
    if (D_8017966D == 0 && !(D_8017966A & 7)) {
        for (i = 0; i < 2; i++) {
            if (D_80179680[i] != 0) {
                D_8017967E[i] -= 4;
                if (D_8017967E[i] < 0x10) {
                    func_8004A4C0(i);
                }
            }
        }
    }
    if (D_8017967A != 0 && D_8017966D == 0 && !(D_8017966A & 7)) {
        D_8017967A--;
        D_80179678++;
    }
    if (D_8017967B != 0 && !(D_8017966A & 1)) {
        D_8017967C += D_8017967B;
        if (D_8017967C == 0xCA || D_8017967C == 0) {
            D_8017967B = 0;
        }
    }
    for (D_8017966C = 0; D_8017966C < 16; D_8017966C++) {
        D_80179924 = &D_8018C980[D_8017966C];
        if (D_80179924->unkF != 0) {
            D_80179924->unkF--;
            if (D_80179924->unkF == 0 && D_80179924->unkE != 0) {
                D_80179924->unkE = 0;
                func_8005FDD0(D_8007C910, &D_80179760[D_8017966C]);
            }
        }
        if (D_80179924->unk0 != 0) {
            if (D_80179924->unk5 != 0) {
                D_80179924->unk5--;
            } else if ((D_80179924->unk0 & 0x7FFF) < 0x100U) {
                if (D_8017966D == 0) {
                    D_80179924->unk1A += D_80179678;
                    func_8004A9A4();
                }
            } else {
                func_8004A9A4();
            }
        }
    }
}
