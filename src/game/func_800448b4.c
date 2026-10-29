typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef struct {
    u16 unk0;
    u16 pad2;
    u16 unk4;
    u8 pad6[6];
    float unkC;
    float unk10;
    float unk14;
    u8 pad18[0x114];
    int unk12C;
    u8 pad130[0x18];
} Rec; /* 0x148 */
typedef struct { char pad[0x8B2C0]; Rec objs[1]; } W;

typedef struct {
    float x;
    float y;
    u8 pad8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 type;
    u8 padD[7];
    u8 timer14;
    u8 timer15;
    s16 unk16;
    u8 unk18;
    s8 unk19[7];
    float unk20;
    u8 unk24;
    u8 pad25[3];
} Ent; /* 0x28 */

extern u8 D_801369F0;
extern s16 D_80136A26[];
extern s16 D_80136A0A[];
extern s16 D_80136A06[];
extern s16 D_80136A04[];
extern u8 D_801369EC[];
extern u8 D_80136A10;
extern u8 D_80136A11;
extern u8 D_80136A12;
extern u8 D_80136A13;
extern u8 D_80136A14;
extern u8 D_80136A15;
extern u8 D_80136A16;
extern u8 D_80136A17;
extern u8 D_80136A18;
extern s16 D_80136A1A;
extern s16 D_80136A1C;
extern s16 D_80136A1E;
extern u8 D_80136A20;
extern s16 D_80136A22;
extern u8 D_80136A24;
extern u8 D_80136A25;
extern Ent D_80136A28[15];
extern Ent D_80136C80[];
extern char *D_80126BF0;
extern u8 D_80138301;
extern float D_80138240[];
extern float D_8013825C;
extern int D_80138260[];
extern float D_80138264;
extern float D_80138270;
extern u8 D_80138274[];
extern u8 D_80138280[][3];
extern int D_800725B0[];
extern u8 *D_800731D0[];
extern float D_800731D8[];
extern float D_80073140;
extern float D_80073144;
extern float D_80073150;
extern int D_8019D044[];
extern u8 D_80136A0E[];
extern u8 D_80136A0C[];
extern float D_8007313C[];
float Dxy[2] = { 0.0f, 0.0f };
extern u8 D_80136A08[];
extern u8 D_80136A21[];

extern int func_80043E08(u8 a, int b, int c, float x, float y);
extern void func_80044230(Ent *e, u8 *p, int k);
extern void func_80044658(Ent *e, int a, u8 *p, int b, float f1, float f2, float f3);
extern u8 D_060022F8[];
extern u8 D_06002370[];
extern u8 D_06002308[];
extern u8 D_060086D8[];
extern void func_80044740(Ent *e, int a, u8 *p, float f1, float f2, void *v);
extern int func_80044364(u8 *p, float f);
extern void func_8002B84C(int a, int b);
extern float func_8002AACC();
extern void func_80038C18(int a);
extern float func_80029C18(float *p);
extern void func_80006D84(unsigned int a, void *b);

#define BASE(off) (*(u8 *)(D_80126BF0 + (off)))
#define REC(i) ((Rec *)(D_80126BF0 + 0x8B2C0 + (i) * 0x148))
#if ALIASMASK & 1
#if ALIASSTYLE == 1
#define A22_LOAD (*((s16 *)((u8 *)&D_80136A18 + 10)))
#elif ALIASSTYLE == 2
#define A22_LOAD (*(&D_80136A1A + 4))
#else
#define A22_LOAD (*((s16 *)&D_80136A20 + 1))
#endif
#else
#define A22_LOAD D_80136A22
#endif
#if ALIASMASK & 2
#if ALIASSTYLE == 1
#define A22_STORE1 (*(&D_80136A1C + 3))
#elif ALIASSTYLE == 2
#define A22_STORE1 (*((s16 *)((u8 *)&D_80136A20 + 2)))
#else
#define A22_STORE1 (*((s16 *)&D_80136A24 - 1))
#endif
#else
#define A22_STORE1 D_80136A22
#endif
#if ALIASMASK & 4
#if ALIASSTYLE == 1
#define A22_STORE2 (*(&D_80136A1E + 2))
#elif ALIASSTYLE == 2
#define A22_STORE2 (*((s16 *)((u8 *)&D_80136A18 + 10)))
#else
#define A22_STORE2 (*((s16 *)((u8 *)&D_80136A1E + 4)))
#endif
#else
#define A22_STORE2 D_80136A22
#endif

int func_800448B4(void) {
    char pad[0x20];
    int y;
    int n;
    s16 cnt;
    Ent *e;
    int u;
    int j;
    int m;
    Rec *r;
    u8 *obj;
    int k;
    int t;
    int i;
    int h;
    int q;
    int jj;
    u8 w;
    u8 *obj2;
    u8 kb;
    u8 kc;
    int m1;
    u8 *p = &D_801369F0;

    switch (*p) {
    case 0:
        w = D_80136A10;
        (&D_80136A10)[2] = 0x31;
        D_80136A13 = 0x38;
        D_80136A14 = 0x47;
        (&D_80136A11)[4] = 0x4C;
        D_80136A17 = 0;
        (&D_80136A10)[-0x20] = (&D_80136A17)[-0x27] + 1;
        D_80136A16 = 0;
        D_80136A1A = cnt = (cnt & 0) | 30;
        if (w == 2) {
            D_80136A20 = 4;
        } else {
            D_80136A20 = 2;
        }
        break;
    case 1:
        for (i = D_80136A20; i < 20; i++) { r = REC(i); if (r->unk0 != 0) { if (r->unk10 >= 70.0f) { r->unk10 += 4.0f; } else if (r->unk10 >= -82.5) { if (r->unkC >= 0.0f) { r->unkC += 4.0f; } else { r->unkC -= 4.0f; } } } } cnt = D_80136A26[-6] - 1;
        D_80136A04[11] = cnt;
        if (cnt == 0) {
            y = 17;
            m1 = 0;
            if ((w = D_80136A10) == 0) {
                n = 0;
                func_80043E08(n++, cnt = (cnt & 0) | 2, 0, -370.0f, 65.0f);
                for (i = 0; i < 5; i++) {
                    func_80043E08(n, 1, 0, -370.0f, (float)(65 - n * 16));
                    n++;
                }
                func_80043E08(n++, 2, 1, -370.0f, (float)(65 - n * 16));
                func_80043E08(n++, 1, 0, -370.0f, (float)(65 - n * 16));
                func_80043E08(n++, 1, 0, -370.0f, (float)(65 - n * 16));
                func_80043E08(n++, 3, 0, -360.0f, (float)(65 - n * 16));
                if (BASE(0x977F1) == 0x15) {
                    func_80043E08(n++, 8, 0, 330.0f, (float)(-47 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 0, 330.0f, (float)(-47 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 9, 0, 330.0f, (float)(-47 - m1 * 16));
                } else {
                    func_80043E08(n++, 8, 0, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 0, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 8, 1, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 1, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 6, 1, 340.0f, (float)(-15 - m1 * 16));
                }
            } else if (w == 1) {
                n = 0;
                func_80043E08(n++, 10, 0, -370.0f, (float)(y - n * 16));
                for (i = 0; i < 5; i++) {
                    func_80043E08(n, 11, 0, -370.0f, (float)(y - n * 16));
                    n++;
                }
                func_80043E08(n++, 3, 0, -370.0f, (float)(y - n * 16));
                if (BASE(0x977F1) == 0x15) {
                    func_80043E08(n++, 4, 0, 330.0f, -63.0f);
                    func_80043E08(n++, 9, 0, 330.0f, -79.0f);
                } else {
                    func_80043E08(n++, 6, 0, 330.0f, -79.0f);
                }
            } else {
                n = 0;
                func_80043E08(n++, 10, 0, -370.0f, (float)(y - n * 16));
                for (i = 0; i < 5; i++) {
                    func_80043E08(n, 1, 0, -370.0f, (float)(y - n * 16));
                    n++;
                }
                func_80043E08(n++, 3, 0, -370.0f, (float)(y - n * 16));
                if (BASE(0x977F1) == 0x15) {
                    func_80043E08(n++, 7, 0, 330.0f, (float)(-47 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 0, 330.0f, (float)(-47 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 9, 0, 330.0f, (float)(-47 - m1 * 16));
                } else {
                    func_80043E08(n++, 7, 0, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 0, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 7, 1, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 4, 1, 340.0f, (float)(-15 - m1 * 16));
                    m1++;
                    func_80043E08(n++, 6, 1, 340.0f, (float)(-15 - m1 * 16));
                }
            }
            n--;
            D_80136A1C = D_80136A28[n].unkA;
            ((s16 *)&D_80136A10)[7] = D_80136A28[n].unkA;
            (&D_80136A10)[-0x20]++;
            D_80136A0A[8] = cnt = (cnt & 0) | 140;
        }
        break;
    case 2:
        if ((kb = D_80136A24) == 0) {
            if ((&D_80136A17)[1] == 0) {
                u = *(s16 *)(&D_80136A20 + 2);
                if (u < 255) {
                    u = (s16)(u + 5);
                    A22_STORE1 = u;
                    if (u >= 255) {
                        u = (u & 0) | 255;
                        (&D_80136A1E)[2] = u;
                    }
                }
                if ((h = func_80044364(p, 16.0f)) != 0) {
                    kc = D_80136A10;
                    if (h) {}
                    if (kc == 0) {
                        func_8002B84C(0, D_80138260[BASE(0x977F2) * 2 + 1]);
                    } else if (kc == 1) {
                        func_8002B84C(0, *(int *)&D_80138270);
                    } else {
                        func_8002B84C(0, D_80138260[BASE(0x977F2) * 2]);
                    }
                    (&D_80136A10)[8] = D_80136A18 + 1;
                    cnt = (cnt & 0) | 140;
                    r = (Rec *)(((int)r & 0) | 1);
                    D_80136A1C = *(s16 *)(&D_80136A10 + 0xE);
                    D_80136A0A[8] = cnt;
                    (&D_80136A14)[16] = (int)r;
                    for (i = 0; i < 15; i++) {
                        e = &D_80136A28[i];
                        if (e->type != 0) {
                            e->unk16 = 140;
                            e->unk9 = 0;
                            e->unkA = e->unkB;
                        }
                    }
                }
            }
        } else if (kb == 1) {
            for (i = 0; i < 15; i++) {
                e = &D_80136A28[i];
                if (e->type != 0 && e->unk18 == 1) {
                    if (e->unk24 == 0) {
                        r = &((W *)D_80126BF0)->objs[(unsigned)e->unk19[0]];
                        if (r->unk4 == 0x932 || r->unk4 == 0x900 || r->unk4 == 0xA00 || r->unk4 == 0x910 || r->unk4 == 0xA10 || r->unk4 == 0x820 || r->unk4 == 0x920 || r->unk4 == 0xA20) {
                            r->unkC = e->unk20;
                            e->unk18 = 0;
                        }
                        if (e->type == 6 || e->type == 9) {
                            D_80138301 = 12;
                            (&D_80136A13)[0x12] = 0;
                            D_80136A0C[0x18] = (int)(r = (Rec *)(((int)r & 0) | 2));
                        }
                    } else {
                        e->unk24--;
                    }
                }
            }
        } else if (kb == 2) {
            t = D_80136A25;
            u = t;
            if (t == 0) {
                if (--D_80138301 == 0) {
                    D_80136A21[4] = t = t + 1;
                }
            } else if ((u | 0) == 1) {
                *(float *)(D_80126BF0 + 0x8B410) = func_8002AACC();
                func_80038C18(1);
                if (kb) {}
                D_801369EC[4]++;
            }
        }
        break;
    case 4:
        u = D_80136A26[-2];
        if (u != 0) {
            u = (s16)(u - 5);
            ((s16 *)D_80136A0E)[10] = u;
            if (u < 0) {
                ((s16 *)D_80136A0C)[11] = 0;
            }
        }
        if (func_80044364(p, -16.0f) != 0) {
            for (i = 34; i < 83; i++) {
                r = REC(i);
                r->unk0 = 0;
                r->unk4 = 0;
                r->unk14 = 0.0f;
                r->unk10 = 0.0f;
                r->unkC = 0.0f;
            }
            e = D_80136A28;
            for (i = 0; i < 15; i++) {
                e[i].unk9 = 0;
                e[i].type = 0;
            }
            D_801369EC[4]++;
            D_80136A04[11] = cnt = (cnt & 0) | 30;
        }
        break;
    case 5:
        cnt = D_80136A0A[8] - 1;
        D_80136A06[10] = cnt;
        if (cnt == 0) {
            for (i = 34; i < 83; i++) {
                r = REC(i);
                r->unk0 = 0;
                r->unk12C = 0;
            }
            D_801369EC[4] = 6;
        }
        break;
    case 3:
    case 6:
        break;
    }

    if (D_801369EC[4] != 6) {
        D_80136A11 = 0x22;
        if (D_801369EC[4] >= 2 && D_801369EC[4] < 5) {
            for (i = 0; i < 15; i++) {
                e = &D_80136A28[i];
                switch (e->type) {
                case 0:
                    break;
                case 1:
                    func_80044230(e, p, 0);
                    if (e->timer15 == 0) {
                        e->unk19[0] = D_80136A0E[4];
                        Dxy[0] = e->x + 110.5;
                        Dxy[1] = e->y - 1.0f;
                        (&D_80073140)[4] = 1.0f;
                        r = &((W *)D_80126BF0)->objs[(int)p[0x22]];
                        func_80006D84(p[0x22]++, &D_80073140);
                        r->unk12C = D_800725B0[D_80138274[D_80136A0C[0xB]]];
                        (&D_80136A10)[7] = D_80136A17 + 1;
                        func_80044658(e, 1, p, 0x900, D_800731D8[D_80136A10], 0.0f, D_80138240[p[0x26]++]);
                        e->timer15++;
                    }
                    break;
                case 2:
                    func_80044230(e, p, 2);
                    if (e->timer15 == 0) {
                        func_80044740(e, 1, p, 120.5f, 1.0f, D_060022F8);
                        func_80044658(e, 0, p, 0x800, 160.5f, 0.0f, (float)(e->timer14 + 1));
                        e->timer15++;
                    }
                    break;
                case 3:
                    func_80044230(e, p, 1);
                    if (e->timer15 == 0) {
                        if ((w = D_80136A10) == 0) {
                            func_80044658(e, 0, p, 0xA10, D_800731D8[w], 0.0f, D_8013825C);
                        } else {
                            func_80044658(e, 0, p, 0x910, D_800731D8[w], 0.0f, D_8013825C);
                        }
                        e->timer15++;
                    }
                    break;
                case 4:
                    func_80044230(e, p, 0);
                    if (e->timer15 == 0) {
                        if (BASE(0x977F2) >= e->timer14) {
                            if (BASE(0x977F1) == 0x15) {
                                if ((w = D_80136A10) == 0) {
                                    func_80044658(e, 0, p, 0xA00, -61.5f, 0.0f, D_80138264);
                                } else {
                                    func_80044658(e, 0, p, 0x900, -72.5f, 0.0f, D_80138264);
                                }
                            } else if ((w = D_80136A10) == 0) {
                                func_80044658(e, 0, p, 0xA10, -61.5f, 0.0f, *(float *)&D_80138260[e->timer14 * 2 + 1]);
                            } else {
                                func_80044658(e, 0, p, 0x910, -72.5f, 0.0f, *(float *)&D_80138260[e->timer14 * 2 + 1]);
                            }
                        }
                        e->timer15++;
                    }
                    break;
                case 6:
                    func_80044230(e, p, 1);
                    if (e->timer15 == 0) {
                        func_80044740(e, 1, p, -160.5f, 1.0f, D_06002370);
                        if ((kc = D_80136A10) == 2 || kc == 1) {
                            func_80044658(e, 0, p, 0x920, -72.5f, 0.0f, D_80138270);
                        } else {
                            func_80044658(e, 0, p, 0xA20, -61.5f, 0.0f, D_80138270);
                        }
                        e->timer15++;
                    }
                    break;
                case 7:
                    func_80044230(e, p, 0);
                    if (e->timer15 == 0) {
                        if (BASE(0x977F1) == 0x15) {
                            func_80044740(e, 0, p, -160.5f, 1.0f, D_06002308);
                            if (BASE(0x977F2) >= e->timer14) {
                                func_80044658(e, 1, p, 0x932, -63.5f, 0.0f, *(float *)&D_80138260[e->timer14 * 2]);
                            }
                        } else {
                            func_80044740(e, 1, p, -160.5f, 1.0f, D_06002308);
                            func_80044658(e, 0, p, 0x800, -123.5f, 0.0f, (float)(e->timer14 + 1));
                            if (BASE(0x977F2) >= e->timer14) {
                                func_80044658(e, 2, p, 0x932, -63.5f, 0.0f, *(float *)&D_80138260[e->timer14 * 2]);
                            }
                        }
                        e->timer15++;
                    }
                    break;
                case 8:
                    func_80044230(e, p, 0);
                    if (e->timer15 == 0) {
                        if (BASE(0x977F1) == 0x15) {
                            func_80044740(e, 0, p, -160.5f, 1.0f, D_06002308);
                        } else {
                            func_80044740(e, 1, p, -160.5f, 1.0f, D_06002308);
                        }
                        if (BASE(0x977F1) != 0x15) {
                            func_80044658(e, 0, p, 0x800, -123.5f, 0.0f, (float)(e->timer14 + 1));
                            m = 2;
                        } else {
                            m = 1;
                        }
                        if (BASE(0x977F2) >= e->timer14) {
                            for (j = 0, jj = 0; j < 3; jj += 11, j++) {
                                obj = D_800731D0[e->timer14 & 1];
                                e->unk19[m + j] = (&D_80136A13)[2];
                                *(int *)(obj + 0x24) = D_8019D044[D_80138280[BASE(0x977EF) * 2 + e->timer14][j]];
                                *(float *)obj = e->x - 113.5 + (double)jj;
                                *(float *)(obj + 4) = e->y - 1.0f;
                                func_80006D84(p[0x25]++, D_800731D0[e->timer14 & 1]);
                            }
                        }
                        e->timer15++;
                    }
                    break;
                case 9:
                    func_80044230(e, p, 1);
                    if (e->timer15 == 0) {
                        func_80044740(e, 1, p, -160.5f, 2.0f, D_060086D8);
                        func_80044658(e, 0, p, 0x820, -87.5f, 0.0f, func_80029C18(&D_80138270));
                        e->timer15++;
                    }
                    break;
                case 10:
                    func_80044230(e, p, 2);
                    if (e->timer15 == 0) {
                        func_80044740(e, 0, p, 120.5f, 1.0f, D_060022F8);
                        e->timer15++;
                    }
                    break;
                case 11:
                    func_80044230(e, p, 0);
                    if (e->timer15 == 0) {
                        h = D_80136A16;
                        func_80044658(e, 1, p, 0x804, 124.5f, 0.0f, (float)(h / 2 + 1));
                        p[0x26]++;
                        e->unk19[0] = p[0x22];
                        D_8007313C[1] = e->x + 132.5;
                        D_80073144 = e->y - 2.0f;
                        (&D_80073140)[4] = 1.0f;
                        r = &((W *)D_80126BF0)->objs[(int)p[0x22]];
                        func_80006D84(p[0x22]++, &D_80073140);
                        r->unk12C = D_800725B0[D_80138274[D_80136A0C[0xB]]];
                        (&D_80136A11)[6] = D_80136A17 + 1;
                        func_80044658(e, 2, p, 0x900, 194.5f, 0.0f, D_80138240[(int)(&D_80136A11)[5] / 2]);
                        D_80136A16++;
                        e->timer15++;
                    }
                    break;
                }
            }
        }
    }
    return *p;
}
