typedef struct Voice {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x2F];
    short level;
    unsigned char pad38[0x5C];
    unsigned char rateGate;
    unsigned char rateStep;
    unsigned short phase;
    unsigned char lfoPos;
    unsigned char lfoStep;
    unsigned char pad9A[2];
    unsigned short depth;
} Voice;

extern Voice *D_80179924;
extern unsigned char D_80073AE0[];

void func_8004C6D4(void) {
    if (D_80179924->rateGate == 0) {
        D_80179924->phase += D_80179924->rateStep;
        if (D_80179924->phase >= 0x100) {
            D_80179924->phase &= 0xFF;
            D_80179924->flags |= 2;
            D_80179924->lfoPos += D_80179924->lfoStep;
            D_80179924->lfoPos &= 0x3F;
            if (D_80179924->depth < 0x8000) {
                D_80179924->level = D_80179924->depth >> 7;
                D_80179924->level = (D_80073AE0[D_80179924->lfoPos & 0x1F] * D_80179924->level) >> 8;
            } else {
                D_80179924->level = (D_80179924->depth >> 8) & 0x7F;
                D_80179924->level += 2;
                D_80179924->level = (D_80073AE0[D_80179924->lfoPos & 0x1F] * D_80179924->level) >> 1;
            }
            if (D_80179924->lfoPos >= 0x20) {
                D_80179924->level = -D_80179924->level;
            }
        }
    }
}
