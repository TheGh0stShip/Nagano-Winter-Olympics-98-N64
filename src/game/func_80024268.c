typedef struct A { float x, y, z, h; } A;
typedef struct B { float x, y, ground; } B;
typedef struct C { unsigned char pad[0x28]; int state; float drop; } C;

extern unsigned short D_80137130;
extern int func_80024478(A *, B *, C *);
extern void func_80048580(int);
extern void func_800485AC(int);

int func_80024268(A *a, B *b, C *c) {
    long long pad;
    int pad2;
    int ret = 0;
    float f;
    float h, drop, ground;

    switch (c->state) {
    case 1:
        D_80137130++;
        f = a->h - c->drop;
        if (f < b->ground) {
            c->state = 2;
            ret = 0x2000;
            a->h = b->ground;
            c->drop = 0.0f;
        } else {
            a->h = f;
            c->drop += 1.0;
        }
        break;
    case 2:
        c->state = 0;
        c->drop = a->h - b->ground;
        a->h = b->ground;
        if (D_80137130 > 60) {
            func_800485AC(0x21E);
        } else if (D_80137130 > 30) {
            func_800485AC(0x21F);
        } else {
            func_800485AC(0x220);
        }
        break;
    default:
    case 0:
        if (func_80024478(a, b, c)) {
            c->drop = a->h - b->ground;
            a->h = b->ground;
        } else {
            f = a->h - c->drop;
            if (f - b->ground > 6.5) {
                c->state = 1;
                ret = 0x1000;
                a->h -= c->drop;
                c->drop += 1.0;
                func_80048580(0x21D);
                D_80137130 = 0;
            } else {
                c->drop = a->h - b->ground;
                a->h = b->ground;
            }
        }
        break;
    }
    return ret;
}
