typedef struct Rec {
    unsigned short kind;
    unsigned short state;
    unsigned char pad4[8];
    float x;
    float y;
    float z;
    unsigned char pad18[0x114];
    int value;
    unsigned char pad130[8];
} Rec;

typedef struct Blob112 {
    unsigned char bytes[0x112];
} Blob112;

typedef struct BlobC4 {
    unsigned char bytes[0xC4];
} BlobC4;

extern unsigned char *D_80126BF0;
extern unsigned char D_80137704;
extern unsigned char D_801376D0[];
extern char D_80072450[];
extern char D_800725F0[];
extern char D_8007258C[];
extern int D_800725B0[];
extern int D_8007263C[];
extern int D_8007264C;
extern int D_80072658[];
extern int D_80072674[];
extern int D_80072684;

extern void func_80033554(void);
extern void func_8000ED68(void *);
extern void func_8000EC50(void *);
extern void func_80009358(short, int, void *);
extern void func_80035004(short, unsigned char *);
extern void func_800437A0(unsigned short, void *, int, unsigned short, unsigned short);

#define REC(i) (((Rec *)(D_80126BF0 + 0x83EF8))[i])
#define ROW(i) (*(float *)(D_80126BF0 + 0x86608 + (i) * 0x138))

void func_80032E94(void) {
    short i;
    short idx;
    short count;
    BlobC4 small;
    Blob112 big180;
    unsigned char pair[2];
    Blob112 big68;

    func_80033554();
    if (D_80137704 == 0) {
        count = D_80126BF0[0x90000 + 0x77F0];
    } else if (D_80137704 == 1) {
        if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
            func_8000ED68(&small);
            count = small.bytes[1];
        } else {
            func_8000EC50(&big180);
            count = big180.bytes[1];
        }
    }
    for (i = 0; i < 4; i++) {
        idx = i + 0x20;
        func_80009358(idx, 10, D_80072450);
        REC(idx).x = 208.0f;
        REC(idx).y = 27.0f - i * 19.0f - 120.0f;
        REC(idx).z = -20.0f;
        REC(idx).state = 1;
        if (i < count) {
            idx = i + 0x24;
            func_80009358(idx, 10, D_800725F0);
            if (D_80137704 == 0) {
                REC(idx).value = D_800725B0[D_801376D0[i]];
            } else if (D_80137704 == 1) {
                if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
                    REC(idx).value = D_800725B0[small.bytes[small.bytes[i + 2] + 0x96]];
                } else {
                    REC(idx).value = D_800725B0[big180.bytes[i + 0x92]];
                }
            }
            REC(idx).x = 140.8f;
            REC(idx).y = ROW(i);
            if (i >= 2) {
                REC(idx).y -= 0.1f * (i - 1);
            }
            REC(idx).state = 1;
            idx = i + 0x2C;
            if (D_80137704 == 0) {
                func_800437A0(idx, D_8007258C, D_8007264C, 1, 1);
            } else if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
                func_80035004(i, pair);
                idx = i + 0x2C;
                func_800437A0(idx, D_800725F0, D_80072674[pair[0]], 1, 10);
                if (pair[1] != 0) {
                    func_800437A0(idx + 4, D_800725F0, D_80072684, 1, 10);
                    REC(idx + 4).x = 272.2f;
                    REC(idx + 4).y = ROW(i);
                    if (i >= 2) {
                        REC(idx + 4).y -= 0.1f * (i - 1);
                    }
                }
            } else {
                func_8000EC50(&big68);
                idx = i + 0x2C;
                func_800437A0(idx, D_800725F0, D_80072658[big68.bytes[0]], 1, 10);
            }
            REC(idx).x = 260.2f;
            REC(idx).y = ROW(i) + 1.0f;
            if (D_80137704 != 0) {
                REC(idx).y -= 2.0f;
                if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
                    REC(idx).y += 1.0f;
                    REC(idx).x -= 12.0f;
                }
            }
            if (i >= 2) {
                REC(idx).y -= 0.1f * (i - 1);
            }
        }
        idx = i + 0x28;
        func_800437A0(idx, D_8007258C, D_8007263C[i], 1, 1);
        REC(idx).x = 114.8f;
        REC(idx).y = ROW(i) + 1.0f;
        if (i >= 2) {
            REC(idx).y -= 0.1f * (i - 1);
        }
    }
}
