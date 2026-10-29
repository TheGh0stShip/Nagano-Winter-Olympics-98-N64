typedef struct { char pad[0x10]; float a; float b; float c; } Cam;
typedef struct { char pad[0x14]; float v[3]; } Obj;
typedef struct { char pad[0x44]; float x, y, z; char pad2[0x54 - 0x50]; unsigned short type; } Ent;
extern unsigned char D_80136C9D;
extern float func_80022F44(float, float, int);
extern void func_80024114(float *, float *, float *);
extern void func_8004E7E0(float *, float, float, float, float);
extern void func_80059410(float *, float, float, float, float *, float *, float *);

void func_80023FA0(Obj *arg0, Cam *arg1, Ent *arg2) {
    float unused[8];
    float out[3];
    float pos[3];
    float res[3];
    float mtx[16];

    if (D_80136C9D == 1) {
        if (arg2->type == 1 || arg2->type == 2 || arg2->type == 4) {
            func_8004E7E0(mtx, 90.0f, 1.0f, 100.0f, 1.0f);
        } else {
            func_8004E7E0(mtx, 90.0f, arg1->a, arg1->b, arg1->c);
        }
    } else {
        func_8004E7E0(mtx, 90.0f, arg1->a, arg1->b, arg1->c);
    }
    func_80059410(mtx, arg2->x, arg2->y, arg2->z, &out[0], &out[1], &out[2]);
    pos[0] = arg2->x;
    pos[1] = arg2->y;
    pos[2] = arg2->z;
    func_80024114(out, pos, res);
    arg0->v[0] += func_80022F44(res[0], arg0->v[0], 0);
    arg0->v[1] += func_80022F44(res[1], arg0->v[1], 0);
    arg0->v[2] += func_80022F44(res[2], arg0->v[2], 0);
}
