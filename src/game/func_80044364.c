typedef struct {
    float f0;
    char pad4[5];
    unsigned char state;
    unsigned char delay;
    char padB;
    unsigned char active;
    char padD[9];
    short timer;
    unsigned char mode;
    signed char ids[7];
    float f20;
    char pad24[4];
} E80044364;
typedef struct {
    unsigned short active;
    char pad2[2];
    unsigned short type;
    char pad6[6];
    float fC;
    char pad10[0x148 - 0x10];
} O80044364;
typedef struct {
    char pad[0x2A];
    short a2A;
    short a2C;
} A80044364;
typedef struct { char pad[0x8B2C0]; O80044364 objs[1]; } W80044364;
extern W80044364 *D_80126BF0;
extern E80044364 D_80136A28[];
extern E80044364 D_80136C80[];

int func_80044364(A80044364 *arg0, float arg1) {
    signed char *p;
    E80044364 *e;
    O80044364 *o;
    int j;
    int id;
    float a;

    j = 0; o = 0; id = 0;
    e = D_80136A28; do {
        if (e->active == 0) continue;
        if (e->delay != 0) { e->delay--; continue; }
        if (e->state != 0) continue;
        if (e->f0 < 0.0f) e->f0 += arg1; else e->f0 -= arg1;
        if (e->mode == 0) {
            for (j = 0, p = (signed char *)e; j != 7; j++, p++) {
                id = p[0x19];
                if (id < 0) break;
                o = &D_80126BF0->objs[id];
                if (o->active) {
                    if (e->f0 < 0.0f) o->fC += arg1; else o->fC -= arg1;
                }
            }
        } else {
            for (j = 0, p = (signed char *)e; j != 2; j++, p++) {
                id = p[0x19];
                if (id < 0) break;
                o = &D_80126BF0->objs[id];
                if (o->active) {
                    if (o->type == 0x932 || o->type == 0x900 || o->type == 0xA00 || o->type == 0x910 || o->type == 0xA10 || o->type == 0x820 || o->type == 0x920 || o->type == 0xA20) {
                        if (e->f0 < 0.0f) e->f20 += arg1; else e->f20 -= arg1;
                    } else {
                        if (e->f0 < 0.0f) o->fC += arg1; else o->fC -= arg1;
                    }
                }
            }
        }
        e->timer -= 0x10;
        if (e->timer <= 0) e->state++;
    } while (++e != D_80136C80);
    if (arg0->a2C == 0) {
        a = arg1 < 0.0f ? -arg1 : arg1;
        arg0->a2A = arg0->a2A - a;
        if (arg0->a2A < 0) return 1;
    } else {
        arg0->a2C--;
    }
    return 0;
}

