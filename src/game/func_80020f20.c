typedef struct { unsigned short flags; short pad2; short speed; char pad6[8]; } Kart;
typedef struct {
    char pad0[0x7C8F6];
    Kart karts[(0x977EC - 0x7C8F6) / 14];
    char padx[0x977EC - 0x7C8F6 - ((0x977EC - 0x7C8F6) / 14) * 14];
    unsigned char mode;
    char pad977ED[2];
    unsigned char player;
    char pad977F0[4];
    unsigned char demo;
} Game;
typedef struct { float a[3]; float b[3]; } Seg;
typedef struct { char pad0[0x10]; float x, y, z; } Cam;
typedef struct {
    char pad0[0x24];
    short steer;
    short flag;
    char pad28[0x31 - 0x28];
    unsigned char ai;
    unsigned char aiId;
    char pad33[0x38 - 0x33];
    float f38;
    float f3C;
    float f40;
    float pos[3];
    char pad50[0x54 - 0x50];
    unsigned short state;
    unsigned short count;
} Drv;
extern Game *D_80126BF0;
extern unsigned short D_80137112;
extern unsigned char D_80136C9D;
extern signed char D_800704C0[];
extern signed char D_800704C4[];
extern Seg D_8019D348[];
extern short func_80021260(unsigned char);
extern int func_80021278(unsigned char);
extern float func_800212B4(float, float);
extern float func_80021408(float *, float *);
extern void func_8004E7E0(float *, float, float, float, float);
extern void func_80059410(float *, float, float, float, float *, float *, float *);

void func_80020F20(Drv *d, Cam *c) {
    float mtx[16];
    float a[3];
    float b[3];
    float r;

    if (d->ai) {
        d->steer = func_80021260(d->aiId);
        d->flag = 0;
        if (func_80021278(d->aiId)) {
            d->flag = 1;
        }
    } else {
        d->steer = D_80126BF0->karts[D_80126BF0->player].speed / 8;
        d->flag = 0;
        if (D_80126BF0->karts[D_80126BF0->player].flags & 0x8000) {
            d->flag = 1;
        }
    }
    if (D_80126BF0->demo) {
        d->steer = D_800704C4[D_80137112];
        d->flag = 0;
        D_80137112++;
    }
    if (d->state == 1) {
        Seg *s = &D_8019D348[D_80136C9D];
        func_8004E7E0(mtx, 90.0f, s->a[0] - s->b[0], s->a[1] - s->b[1], s->a[2] - s->b[2]);
        func_80059410(mtx, c->x, c->y, c->z, &a[0], &a[1], &a[2]);
        func_8004E7E0(mtx, 90.0f, c->x, c->y, c->z);
        func_80059410(mtx, a[0], a[1], a[2], &b[0], &b[1], &b[2]);
        r = func_80021408(b, d->pos);
        if (r > 0.02) {
            d->steer = -10;
            d->flag = 1;
        } else if (r < -0.02) {
            d->steer = 10;
            d->flag = 1;
        } else {
            d->steer = 0;
            d->flag = 1;
            d->count++;
        }
    }
    if (d->state == 2) {
        if (func_800212B4(d->f38, d->f40) < 0.0f) {
            d->steer = D_800704C0[D_80136C9D];
            d->steer = -d->steer;
        } else {
            d->steer = D_800704C0[D_80136C9D];
        }
        d->flag = 0;
    }
    if (d->state == 4) {
        d->steer = 0;
        d->flag = 0;
    }
    if (d->state == 8) {
        d->steer = 0;
        d->flag = 0;
    }
}
