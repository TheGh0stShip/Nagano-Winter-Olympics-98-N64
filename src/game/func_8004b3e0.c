typedef struct {
    unsigned int id;
    char pad4[2];
    unsigned char flags;
    char pad7[0x3A - 7];
    unsigned short vol;
    char pad3C[0x40 - 0x3C];
    short v40;
    short v42;
    char pad44[0x48 - 0x44];
    unsigned char v48;
    char pad49;
    unsigned short v4A;
    unsigned short v4C;
    char pad4E[0xA4 - 0x4E];
    unsigned short vA4;
    char padA6[0xAC - 0xA6];
    short lastVol;
    unsigned short lastPitch;
    char padB0[0xB6 - 0xB0];
    unsigned char vB6;
    char padB7[0xC0 - 0xB7];
    short vC0;
} Chan;
typedef struct {
    char data[0x1C];
} Voice;
extern Chan *D_80179924;
extern int D_8007C910;
extern unsigned char D_8017966C;
extern signed char D_8017966E;
extern unsigned char D_8017966F;
extern unsigned char D_80179671;
extern unsigned char D_80179673;
extern unsigned char D_80179674;
extern unsigned char D_80179676;
extern signed char D_8017967B;
extern unsigned char D_8017967C;
extern unsigned char D_8017967E[];
extern unsigned short D_80179680[];
extern Voice D_80179760[];
extern int func_8004A560(unsigned char);
extern int func_8004B384(int, unsigned char, unsigned char);
extern void func_8004EB90(int, Voice *, short, int);

void func_8004B3E0(void) {
    int vol;
    int pitch;
    unsigned short m;
    short v;
    short w;
    unsigned char k;
    int id;
    int i;

    D_80179924->flags &= 0xFE;
    vol = D_80179924->v48 + D_80179924->v40 + D_80179924->v42;
    vol *= D_80179924->vol;
    if (vol >= 0x800000) {
        vol = 0x7FFF;
    } else if (vol < 0) {
        vol = 0;
    } else {
        vol >>= 8;
    }
    m = D_80179924->vA4;
    pitch = D_80179924->v4C;
    vol = (D_80179924->v4A * vol) >> 8;
    if (m) {
        vol = (m * vol) >> 8;
        if (vol >= 0x8000) vol = 0x7FFF;
    }
    v = D_80179924->vC0;
    if (v) {
        w = v / 64;
        if (w < -0xFF) {
            vol = 0;
        } else {
            vol = ((w + 0x100) * vol) >> 8;
            if (vol >= 0x8000) vol = 0x7FFF;
        }
    }
    k = D_80179924->vB6;
    if (k) {
        vol = (k * vol) >> 8;
        pitch = func_8004B384(pitch, k, 2);
    }
    if (D_80179676 && func_8004A560(D_8017966C)) {
        vol = (D_80179676 * vol) >> 8;
        pitch = func_8004B384(pitch, D_80179676, D_80179674);
    }
    if ((D_80179924->id & 0x7FFF) < 0x100) {
        if (D_80179673) {
            vol = (D_80179673 * vol) >> 8;
            pitch = func_8004B384(pitch, D_80179673, D_80179671);
        }
        if (D_8017967C) {
            vol = (D_8017967C * vol) >> 8;
            if (D_8017967B < 0) {
                pitch = func_8004B384(pitch, D_8017967C, 2);
            }
        }
    }
    id = D_80179924->id & 0x7FFF;
    if (D_8017966F && id != 0x468 && id != 0x46A) {
        vol = (D_8017966F * vol) >> 8;
        if (D_8017966E < 0) {
            pitch = func_8004B384(pitch, D_8017966F, 1);
            id = D_80179924->id & 0x7FFF;
        }
    }
    for (i = 0; i < 2; i++) {
        if (id == D_80179680[i]) {
            vol = (D_8017967E[i] * vol) >> 8;
            pitch = func_8004B384(pitch, D_8017967E[i], 2);
            break;
        }
    }
    if (D_80179924->lastVol != (short)vol || D_80179924->lastPitch != (unsigned short)pitch) {
        D_80179924->lastVol = vol;
        D_80179924->lastPitch = pitch;
        func_8004EB90(D_8007C910, &D_80179760[D_8017966C], vol, pitch * 5000);
    }
}
