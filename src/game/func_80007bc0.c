typedef struct RecordA {
    unsigned char pad0[8];
    void *field_08;
    unsigned char padC[0x14];
    void *field_20;
} RecordA;

typedef struct RecordB {
    unsigned char pad0[8];
    void *field_08;
    unsigned char padC[0xC];
} RecordB;

typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_800690E0;
extern InitBlock D_8006C358;
extern void *D_8006C0C0[];
extern void *D_8006C140[];
extern void *D_8006C1C0[];
extern void *D_8006C240[];
extern void *D_8006C2C0[];
extern unsigned char *D_80126BF0;
extern void *func_80005E18(int);
extern void func_800090CC(short, unsigned char, void *);
extern void func_8000916C(short, unsigned char, void *);
extern void func_80009228(short, unsigned char, void *);
extern void func_800092C0(short, unsigned char, void *);
extern void func_80009358(short, unsigned char, void *);

void func_80007BC0(short index, void *entry) {
    RecordA *a;
    short i;
    int unused1;
    int unused2;
    RecordB *b;

    *(InitBlock *)(D_80126BF0 + 0x7FFD8) = D_800690E0;
    entry = D_8006C1C0[index];
    if (entry != 0) {
        a = func_80005E18(0);
        i = 0;
        if (a->field_08 != 0) {
            do {
                func_80009228(i, 0, a);
                i++;
                b++;
            } while (a->field_08 != 0);
        }
    }
    *(InitBlock *)(D_80126BF0 + 0x800C8) = D_8006C358;
    entry = D_8006C240[index];
    if (entry != 0) {
        a = func_80005E18(0);
        i = 0;
        if (a->field_20 != 0) {
            do {
                func_800092C0(i, 0, a);
                i++;
                b++;
            } while (a->field_20 != 0);
        }
    }
    entry = D_8006C0C0[index];
    if (entry != 0) {
        b = func_80005E18(0);
        i = 0;
        if (b->field_08 != 0) {
            do {
                func_800090CC(i, 0, b);
                i++;
                b++;
            } while (b->field_08 != 0);
        }
    }
    entry = D_8006C140[index];
    if (entry != 0) {
        b = func_80005E18(0);
        i = 0;
        if (b->field_08 != 0) {
            do {
                func_8000916C(i, 0, b);
                i++;
                b++;
            } while (b->field_08 != 0);
        }
    }
    entry = D_8006C2C0[index];
    if (entry != 0) {
        a = func_80005E18(0);
        i = 0;
        if (b->field_08 != 0) {
            do {
                func_80009358(i, 0, a);
                i++;
                a++;
            } while (b->field_08 != 0);
        }
    }
}
