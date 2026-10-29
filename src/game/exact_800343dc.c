typedef struct Blob112 {
    unsigned char bytes[0x112];
} Blob112;

typedef struct BlobC4 {
    unsigned char bytes[0xC4];
} BlobC4;

typedef struct Runtime {
    unsigned char pad0[0x977EE];
    unsigned char slotA;
    unsigned char pad977EF;
    unsigned char count;
    unsigned char mode;
} Runtime;

extern Runtime *D_80126BF0;
#define RT ((unsigned char *)D_80126BF0)
extern unsigned char D_801376D0[];
typedef struct NameEntry {
    unsigned char text[9];
} NameEntry;

extern NameEntry D_801376D8[];
extern int D_801386A4;

extern unsigned short func_80005C48(void);
extern void func_80048580(unsigned short);
extern void func_8002FD50(void *, int, int, int, int, int, int);
extern void func_8000EC50(void *);
extern void func_8000ED68(void *);

short func_800343DC(short arg0, unsigned char *arg1) {
    short result;
    short i;
    short j;
    short sum;
    unsigned short flags;
    Blob112 big;
    BlobC4 small;

    result = 0;
    sum = 0;
    for (i = 0; i < 4; i++) { sum += *(short *)(RT + 0x78000 + i * 14 + 0x48FA) / 32; }
    flags = func_80005C48();
    if (arg0 != 0) {
        if (*(float *)(RT + 0x880D8) < -222.0f) {
            *(float *)(RT + 0x880D8) += 1.0f;
        }
    } else if (*(float *)(RT + 0x880D8) > -264.0f) {
        *(float *)(RT + 0x880D8) -= 1.0f;
        if (*(float *)(RT + 0x880D8) == -264.0f) {
            *arg1 = 0;
        }
    } else {
        if ((flags & 0x100) || sum > 0) {
            if (*arg1 == 0) {
                func_80048580(0x46A);
            }
            *arg1 = 1;
        } else if ((flags & 0x200) || sum < 0) {
            if (*arg1 == 1) {
                func_80048580(0x46A);
            }
            *arg1 = 0;
        }
        if (*arg1 == 0) {
            func_8002FD50(RT + 0x88CF8, 0, 0, 0, -10, 10, 10);
            func_8002FD50(RT + 0x88F68, 0xAF, 0xAF, 0xAF, -10, 10, 10);
        } else {
            func_8002FD50(RT + 0x88CF8, 0xAF, 0xAF, 0xAF, -10, 10, 10);
            func_8002FD50(RT + 0x88F68, 0, 0, 0, -10, 10, 10);
        }
        if (flags & 0x8000) {
            func_80048580(0x468);
            if (*arg1 != 0) {
                result = -2;
            } else {
                result = 1;
                if (D_80126BF0->mode == 0x15) {
                    func_8000EC50(&big);
                    D_80126BF0->slotA = big.bytes[0];
                    D_80126BF0->count = big.bytes[1];
                    for (i = 0; i < D_80126BF0->count; i++) {
                        for (j = 0; j < 9; j++) {
                            D_801376D8[i].text[j] = big.bytes[i * 9 + j + 2];
                        }
                        D_801376D0[i] = big.bytes[0x92 + i];
                    }
                } else {
                    func_8000ED68(&small);
                    D_80126BF0->count = small.bytes[1];
                    for (i = 0; i < D_80126BF0->count; i++) {
                        for (j = 0; j < 9; j++) {
                            D_801376D8[i].text[j] = small.bytes[small.bytes[2 + i] * 9 + j + 6];
                        }
                        D_801376D0[i] = small.bytes[0x96 + small.bytes[2 + i]];
                    }
                    D_801386A4 = 0;
                }
                func_80048580(7);
            }
        }
    }
    if (result == 0 && (flags & 0x4000)) {
        func_80048580(0x46B);
        result = -1;
    }
    return result;
}
