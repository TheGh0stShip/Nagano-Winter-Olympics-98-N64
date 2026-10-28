typedef struct Acmd {
    unsigned int w0;
    unsigned int w1;
} Acmd;

typedef struct Filter {
    struct Filter *source;
    Acmd *(*handler)(void *filter, short *outp, int outCount, int sampleOffset, Acmd *p);
} Filter;

typedef struct Save {
    Filter filter;
    unsigned char pad8[0xC];
    int dramout;
} Save;

#define ACMD(pkt, a, b) { Acmd *_a = (Acmd *)(pkt); _a->w0 = (a); _a->w1 = (b); }

Acmd *func_8005A804(void *filter, short *outp, int outCount, int sampleOffset, Acmd *p) {
    Acmd *ptr;
    Save *f = (Save *)filter;
    Filter *source = f->filter.source;

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);
    ACMD(ptr++, 0x08000000, (outCount << 1) & 0xFFFF);
    ACMD(ptr++, 0x0D000000, 0x04400580);
    ACMD(ptr++, 0x08000000, (outCount << 2) & 0xFFFF);
    ACMD(ptr++, 0x06000000, f->dramout);
    return ptr;
}
