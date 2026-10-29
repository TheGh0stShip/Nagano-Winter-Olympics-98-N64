typedef struct Slot {
    float x;
    float y;
    unsigned char pad8;
    unsigned char b9;
    unsigned char bA;
    unsigned char bB;
    unsigned char mode;
    unsigned char padD[7];
    unsigned char b14;
    unsigned char b15;
    short h16;
    unsigned char b18;
    signed char tail[7];
    unsigned char pad20[4];
    unsigned char b24;
    unsigned char pad25[3];
} Slot;

extern Slot D_80136A28[];
extern unsigned char D_80138301;
extern unsigned char *D_80126BF0;

void func_80043E08(unsigned char index, unsigned char kind, unsigned char b, float x, float y) {
    Slot *s;
    float d;
    unsigned char v;
    int i;

    s = &D_80136A28[index];
    s->mode = kind;
    s->b9 = 0;
    s->x = x;
    s->y = y;
    if (y < 65.0f) {
        d = -(s->y - 65.0f);
    } else {
        d = s->y - 65.0f;
    }
    v = d / 4 + 1.0f;
    s->bA = v;
    s->bB = v;
    s->h16 = 0x8C;
    s->b14 = b;
    s->b15 = 0;
    s->b18 = 0;
    if (kind == 9) {
        s->b24 = D_80138301;
        s->b18 = 1;
        D_80138301 = D_80138301 + 12.0;
    }
    if (kind == 6) {
        s->b24 = D_80138301;
        s->b18 = 1;
        D_80138301 = D_80138301 + 12.0;
    }
    if (kind == 4) {
        s->b24 = D_80138301;
        v = D_80126BF0[0x977F2];
        if (v == 0) {
            s->b18 = v ^ 1;
        } else if (s->b14 == 0) {
            s->b18 = 0;
        } else {
            s->b18 = 1;
        }
        D_80138301 = D_80138301 + 12.0;
    }
    i = 0; while (i < 7) { s->tail[i] = -1; i++; }
}
