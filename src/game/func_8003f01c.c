typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct Stick {
    s16 x;
    s16 y;
    u8 pad4[10];
} Stick;

extern u8 *D_80126BF0;
extern s16 D_8013822C;
extern u16 D_8013822E;
extern int D_8007270C;
extern int D_80072710;
extern int D_80072714;

extern u16 func_80005C48(void);
extern u16 func_80005CAC(void);
extern void func_80048580(int sound);
extern float func_8002A7E0(void);

s8 func_8003F01C(u8 arg) {
    s8 dir;
    u16 held;
    u16 pressed;
    s16 sumX;
    s16 sumY;
    s16 i;

    dir = 0;
    sumY = 0;
    sumX = 0;
    i = 0; do {
        sumX += ((Stick *)(D_80126BF0 + 0x7C8FA))[i].x / 32;
        i++;
    } while (i < 4);
    i = 0;
    do {
        sumY += ((Stick *)(D_80126BF0 + 0x7C8FA))[i].y / 32;
        i++;
    } while (i < 4);
    held = func_80005C48();
    pressed = func_80005CAC();
    if (arg != 0) {
        D_8013822C = (arg - 1) % 2;
        return 0;
    }
    if (D_8013822C >= 6) {
        dir = D_8013822C - 5;
    } else if (D_8013822C >= 2) {
        D_8013822C += 2;
    } else {
        if (sumX < 0 || (pressed & 0x200)) {
            if (D_8013822C != 0) {
                func_80048580(0x46A);
            }
            D_8013822C = 0;
        } else if (sumX > 0 || (pressed & 0x100)) {
            if (D_8013822C == 0) {
                func_80048580(0x46A);
            }
            D_8013822C = 1;
        }
        if (held & 0x8000) {
            D_8013822C += 2;
            func_80048580(0x468);
        } else if (held & 0x4000) {
            dir = -1;
        }
    }
    if (D_8013822C < 2 && ((D_8013822E % 24) / 12) != 0) {
        *(int *)(D_80126BF0 + 0x84D8C) = D_8007270C;
    } else if (D_8013822C % 2) {
        *(int *)(D_80126BF0 + 0x84D8C) = D_80072714;
    } else {
        *(int *)(D_80126BF0 + 0x84D8C) = D_80072710;
    }
    if (dir != 0) {
        D_8013822C = D_8013822C % 2;
    }
    D_8013822E++;
    return dir;
}
