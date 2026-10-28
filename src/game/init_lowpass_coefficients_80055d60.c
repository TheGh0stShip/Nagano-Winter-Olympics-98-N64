typedef struct LowPass {
    short fc;
    short fgain;
    unsigned char pad4[4];
    short fccoef[16];
    void *fstate;
    int first;
} LowPass;

void func_80055D60(LowPass *lp) {
    int i;
    int temp;
    short fc;
    double ffc;
    double fcoef;

    temp = lp->fc * 16384;
    fc = temp >> 15;
    lp->fgain = 16384 - fc;
    lp->first = 1;
    for (i = 0; i < 8; i++) {
        lp->fccoef[i] = 0;
    }
    lp->fccoef[i++] = fc;
    fcoef = ffc = (double)fc / 16384;
    for (; i < 16; i++) {
        fcoef *= ffc;
        lp->fccoef[i] = (short)(fcoef * 16384);
    }
}
