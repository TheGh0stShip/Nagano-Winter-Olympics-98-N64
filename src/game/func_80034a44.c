typedef struct Rec {
    unsigned short kind;
    unsigned short state;
    unsigned char pad4[8];
    float x;
    float y;
    float z;
    unsigned char pad18[0xC];
    float f24;
    float f28;
    float f2C;
    unsigned char pad30[0xFC];
    int value;
    unsigned char pad130[8];
} Rec;

typedef struct Pad {
    unsigned char pad0[0xE];
} Pad;

extern unsigned char *D_80126BF0;
extern short D_80137706;
extern int D_801386A4;
extern char D_80072450[];
extern char D_80072558[];
extern int D_80072430;
extern int D_80072688;
extern int D_8007268C;
extern int D_80072690;
extern int D_80072538;

extern unsigned short func_80005C48(void);
extern void func_8002FD8C(void *, int, int, int);
extern void func_8002FD50(void *, int, int, int, int, int, int);
extern void func_800437A0(unsigned short, void *, int, unsigned short, unsigned short);
extern void func_80048580(int);
extern void func_80034958(float);

#define B (D_80126BF0)
#define REC(n) (((Rec *)(B + 0x83EF8))[n])
#define R2(n) (((Rec *)(B + 0x7FF90))[n])

short func_80034A44(void) {
    short result;
    unsigned short flag;
    unsigned short buttons;
    short sum;
    float half;
    short i;

    result = 0;
    buttons = func_80005C48();
    sum = 0;
    for (i = 0; i < 4; i++) sum += *(short *)(B + 0x78000 + i * 14 + 0x48FC) / 16;
    if (D_80137706 == 0) {
        for (i = 0; i < 0x5F; i++) {
            REC(i).kind = 0;
        }
        for (i = 0; i < 4; i++) {
            *(int *)(B + 0x86724) = 0;
        }
        REC(0x34).kind = 1;
        flag = REC(0x34).kind;
        REC(0x3C).kind = flag;
        REC(0x3B).kind = flag;
        REC(0x3A).kind = flag;
        REC(0x37).kind = flag;
        REC(0x36).kind = flag;
        REC(0x35).kind = flag;
        REC(0x37).value = D_80072430;
        REC(0x3B).x += 48.0f;
        REC(0x3B).y -= 16.0f;
        REC(0x3C).y -= 16.0f;
        REC(0x34).x = 54.0f;
        REC(0x34).y = -68.0f;
        REC(0x34).z = 10.0f;
        REC(0x34).f2C = 0.5f;
        half = REC(0x34).f2C;
        REC(0x34).f28 = half;
        REC(0x34).f24 = half;
        func_800437A0(0, D_80072450, D_80072688, 1, 1);
        func_800437A0(1, D_80072450, D_8007268C, 1, 1);
        func_800437A0(2, D_80072558, D_80072538, 1, 1);
        func_800437A0(3, D_80072558, D_80072538, 1, 1);
        for (i = 0; i < 4; i++) {
            REC(i).x = 160.0f;
            func_8002FD8C(&REC(i), 0x7F, 0x7F, 0x7F);
            func_8002FD50(&REC(i), 0xAF, 0xAF, 0xAF, -10, 5, 10);
        }
        REC(2).y = -102.0f;
        REC(0).y = REC(2).y;
        REC(3).y = -124.0f;
        REC(1).y = REC(3).y;
        func_800437A0(4, D_80072450, D_80072690, 1, 1);
        REC(4).x = 160.0f;
        REC(4).y = -164.0f;
        D_801386A4 = 0;
        D_80137706++;
    }
    if ((buttons & 0x800) || sum > 0) {
        if (D_801386A4 == 1) {
            func_80048580(0x46A);
        }
        D_801386A4 = 0;
    } else if ((buttons & 0x400) || sum < 0) {
        if (D_801386A4 == 0) {
            func_80048580(0x46A);
        }
        D_801386A4 = 1;
    }
    if (buttons & 0x8000) {
        func_80048580(0x468);
        func_80048580(7);
        result = 1;
    }
    if (D_801386A4 != 0) {
        func_8002FD50(&REC(0), 0x1F, 0x4F, 0x1F, -10, 5, 10);
        func_8002FD50(&REC(1), 0xAF, 0xAF, 0xAF, -10, 5, 10);
    } else {
        func_8002FD50(&REC(0), 0xAF, 0xAF, 0xAF, -10, 5, 10);
        func_8002FD50(&REC(1), 0x1F, 0x1F, 0x1F, -10, 5, 10);
    }
    func_80034958(-76.0f);
    return result;
}
