typedef struct {
    int pad0;
    int pad4;
    int state;
    int timer;
} Task;
typedef struct {
    char pad[0x14];
    unsigned short s14;
    char pad16[0x12];
    long long val;
    short s30;
} Disp;

extern Task D_80137D70;
extern Task D_80137DC0;
extern Task D_80137D98;
extern Task D_80137C70;
extern Task D_80137CD0;
extern Task D_80137C10;
long long D_80137888;
long long D_80137890;
long long D_80137898;
long long D_801378A0;
char D_801378A8[0x958 - 0x8A8];
Disp D_80137958;
char D_80137990[0xA00 - 0x990];
Disp D_80137A00;
char D_80137A38[0xA70 - 0xA38];
Task D_80137A70;
char D_80137A80[0xB08 - 0xA80];
Disp D_80137B08;
Task D_80137B40;
char D_80137B50[0xBD8 - 0xB50];
Disp D_80137BD8;
extern unsigned char D_80137DF5;
extern unsigned char D_80137DF4;
extern unsigned char D_80137DE8;
extern short D_80137CC8;
extern short D_80137D60;
extern char *D_80126BF0;
extern struct { char pad[0x1D0]; float a[16]; float b[16]; } *D_80138210;

extern void func_80037560(Task *);
extern int func_80037CAC(Task *);
extern int func_80037D28(Task *);
extern unsigned short func_80037040(void);
extern void func_80036ED0(int);
extern void func_80036F4C(Disp *, unsigned short);
extern void func_80036F18(void *);
extern void func_80037C10(Task *, int);
extern void func_80037C3C(Task *, int);
extern void func_80038C18(int);
extern int func_80038E0C(int);
extern long long func_8004F02C(long long, long long);
extern long long func_8004F088(long long, long long);
extern long long func_800540FC(float);

void func_80037D94(Task *s) {
    unsigned short v;
    unsigned short x;
    int vi;
    int idx;
    float f;

    if (s->timer != 0) {
        s->timer--;
        func_80037560(s);
        return;
    }
    switch (s->state) {
    case 0:
    case 8:
    case 18:
        break;
    case 1:
        if (func_80037CAC(s)) s->state = 0;
        break;
    case 2:
        if (func_80037D28(s)) s->state = 0;
        break;
    case 3:
        s->timer = 24;
        s->state = 4;
        break;
    case 4:
        v = func_80037040();
        D_80137D70.timer = 0x42;
        D_80137D70.state = 5;
        if (D_80137958.s14 == 0x400) {
            D_80137898 = D_80137888 - D_801378A0;
        } else {
            D_80137898 = func_8004F02C(D_80137888, 10) - func_8004F02C(D_801378A0, 10);
            D_80137898 = func_8004F088(D_80137898, 10);
        }
        func_80036ED0(D_80137DF5);
        D_80137958.val = D_80137898;
        vi = v;
        x = vi;
        x |= 0x120;
        func_80036F4C(&D_80137958, x);
        if (D_80137898 < 0) {
            x = vi;
            x |= 0x130;
            func_80036F4C(&D_80137958, x);
        }
        break;
    case 5:
        func_80036ED0(0);
        if (D_80137DF4 == 0) {
            D_80137DC0.state = 2;
            D_80137DC0.timer = 0;
        }
        D_80137D70.state = 2;
        D_80137D70.timer = 5;
        D_80137D98.state = 2;
        D_80137D98.timer = 10;
        if (D_80137DE8 != 0x3C) {
            D_80137D98.state = 6;
        }
        break;
    case 6:
        if (func_80037D28(s)) {
            switch (D_80137DE8) {
            case 0x40:
                func_80037C10(&D_80137C70, 0);
                func_80037C10(&D_80137CD0, 6);
                D_80137CD0.state = 14;
                s->state = 0;
                D_80137CC8 = 0;
                D_80137D60 = 0;
                break;
            case 0x3E:
            case 0x3F:
                idx = func_80038E0C(D_80126BF0[0x977EF]);
                if (idx < 0) idx = 15;
                func_80037C10(&D_80137A70, 0);
                D_80137B08.val = func_800540FC(D_80138210->a[idx]);
                func_80037C10(&D_80137B40, 6);
                D_80137BD8.val = func_800540FC(D_80138210->b[idx]);
                func_80037C3C(&D_80137C10, 12);
                f = (int)D_80138210->a[idx] / 10 * 10;
                if (0.0f <= D_80138210->b[idx]) {
                    f += (int)D_80138210->b[idx] / 10 * 10;
                }
                D_80137888 = func_800540FC(f);
                D_80137A00.val = func_800540FC(f);
                D_80137C10.state = 9;
                s->state = 0;
                D_80137B08.s30 = 0;
                D_80137BD8.s30 = 0;
                D_80137A00.s30 = 0;
                break;
            case 0x3D:
                s->state = 7;
                break;
            }
        }
        break;
    case 7:
        func_80038C18(1);
        s->state = 0;
        break;
    case 13:
        if (func_80037CAC(s)) s->state = 0;
        break;
    case 9:
        if (func_80037CAC(s)) {
            s->state = 10;
            s->timer = 24;
        }
        break;
    case 10:
        s->state = 11;
        s->timer = 24;
        func_80036F18(&D_80137B08);
        break;
    case 11:
        s->state = 12;
        s->timer = 24;
        func_80036F18(&D_80137BD8);
        break;
    case 12:
        D_80137D98.state = 7;
        D_80137D98.timer = 24;
        s->state = 0;
        func_80036F18(&D_80137A00);
        break;
    case 14:
        if (func_80037CAC(s)) {
            s->state = 15;
            s->timer = 24;
        }
        break;
    case 15:
        s->state = 16;
        s->timer = 24;
        D_80137CC8 = 1;
        break;
    case 16:
        s->state = 17;
        s->timer = 24;
        D_80137D60 = 1;
        break;
    case 17:
        func_80038C18(1);
        s->state = 0;
        break;
    }
    func_80037560(s);
}
