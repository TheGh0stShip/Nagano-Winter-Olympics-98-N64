typedef struct Setup {
    unsigned char count;
    unsigned char group;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
    unsigned char pad5[3];
    int *words;
    short shortC;
    short shortE;
    signed char byte10;
} Setup;

typedef struct Entry {
    int word0;
    unsigned char byte4;
    unsigned char byte5;
    unsigned char pad6[2];
    int word8;
    unsigned char byteC;
    unsigned char pad0D;
    unsigned char byteE;
    unsigned char byteF;
    unsigned char byte10;
    unsigned char pad11[7];
    unsigned short half18;
    unsigned short half1A;
    unsigned char pad1C;
    unsigned char byte1D;
    unsigned char pad1E[3];
    unsigned char byte21;
    unsigned char byte22;
    unsigned char pad23[0xB];
    short half2E;
    short half30;
    short half32;
    short half34;
    unsigned char pad36[2];
    short half38;
    unsigned char pad3A[6];
    short half40;
    short half42;
    unsigned char pad44[3];
    unsigned char byte47;
    unsigned char pad48[0x10];
    short half58;
    unsigned char pad5A;
    unsigned char byte5B;
    unsigned char pad5C[0x21];
    unsigned char byte7D;
    unsigned char pad7E[0xC];
    short half8A;
    unsigned char pad8C[6];
    unsigned char byte92;
    unsigned char pad93[6];
    unsigned short half9A;
    unsigned char pad9C[2];
    unsigned char byte9E;
    unsigned char pad9F[3];
    short halfA2;
    short halfA4;
    signed char byteA6;
    unsigned char padA7[9];
    unsigned char arrB0[3];
    unsigned char arrB3[3];
    unsigned char byteB6;
    unsigned char padB7[7];
    unsigned short arrBE[3];
    unsigned char padC4[6];
    unsigned char arrCA[3];
    unsigned char padCD[3];
} Entry;

extern unsigned int D_801796F8;
extern unsigned char D_80179684[];
extern Setup D_80179688;
extern Entry D_8018C980[];
typedef struct Slot {
    unsigned char bytes[0x1C];
} Slot;
extern Slot D_80179760[];
extern unsigned char D_80179680[];
extern unsigned char D_8017967E[];
extern void *D_8007C910;
extern void func_8005A730(void *a, void *b, unsigned char c);
extern void func_8004EB90(void *a, void *b, int c, int d);

void func_80049B48(void) {
    int flag;
    int i;
    int j;
    int k;
    unsigned int key;
    unsigned char *p;
    Entry *e;
    int *w;

    key = D_801796F8 & 0x7FFF;
    flag = key < 0x100 ? 0 : 1;
    p = &D_80179684[flag];
    w = D_80179688.words;
    for (i = 0, k = 0; i < D_80179688.count; k += sizeof(Entry), i++) {
        e = (Entry *)((unsigned char *)&D_8018C980[D_80179688.group] + k);
        if (e->byte10 != *p) {
            e->byte10 = *p;
            func_8005A730(D_8007C910, (&D_80179760[D_80179688.group] + i), e->byte10);
        }
        if (p != D_80179684) {
            if (e->byteE != 0) {
                func_8004EB90(D_8007C910, (&D_80179760[D_80179688.group] + i), 0, 0x1388);
                e->byteF = 2;
            }
        }
        e->byte5 = D_80179688.byte4;
        e->word0 = D_801796F8;
        e->byte4 = D_80179688.byte2;
        e->byteC = D_80179688.byte3;
        e->word8 = w[i];
        e->half30 = 0;
        e->half34 = 0;
        e->half42 = 0;
        e->half8A = 0;
        e->half18 = 0x8000;
        e->half1A = 0x80;
        e->byte21 = e->byte22 = 1;
        e->half2E = e->half30;
        e->half32 = e->half34;
        e->half40 = e->half42;
        e->byte7D = e->half8A;
        e->byte92 = 0;
        e->half38 = 0;
        e->half9A = (e->byte9E = 0) & 0xFF;
        e->byte1D = 0;
        e->byte47 = 0;
        e->byte5B = 0;
        e->half58 = 0;
        e->halfA2 = D_80179688.shortC;
        e->halfA4 = D_80179688.shortE;
        e->byteA6 = D_80179688.byte10;
        for (j = 0; j < 3; j++) {
            e->arrB0[j] = 0;
            e->arrB3[j] = 0;
        }
        e->byteB6 = 0;
        for (j = 0; j < 3; j++) {
            e->arrBE[j] = 0;
            e->arrCA[j] = 0;
        }
    }
    key = D_801796F8 & 0x7FFF;
    for (i = 0; i < 2; i++) {
        if (key == ((unsigned short *)(D_80179680))[i]) {
            ((unsigned short *)(D_80179680))[i] = D_8017967E[i] = 0;
        }
    }
}

