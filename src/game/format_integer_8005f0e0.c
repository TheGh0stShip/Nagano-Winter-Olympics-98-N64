typedef unsigned int size_t;

typedef struct {
    long long quot;
    long long rem;
} LongLongDiv;

typedef struct {
    union {
        long long ll;
        double ld;
    } v;
    unsigned char *s;
    int n0;
    int nz0;
    int n1;
    int nz1;
    int n2;
    int nz2;
    int prec;
    int width;
    size_t nchar;
    unsigned int flags;
    char qual;
} PrintFormat;

extern LongLongDiv func_8005EF50(long long, long long);
extern void *func_8005A530(void *, const void *, size_t);

static char lowercase_digits[] = "0123456789abcdef";
static char uppercase_digits[] = "0123456789ABCDEF";

void func_8005F0E0(PrintFormat *format, char code) {
    char buffer[24];
    const char *digits;
    int base;
    int index;
    unsigned long long value;

    digits = (code == 'X') ? uppercase_digits : lowercase_digits;
    base = (code == 'o') ? 8 : ((code != 'x' && code != 'X') ? 10 : 16);
    index = 24;
    value = format->v.ll;
    if ((code == 'd' || code == 'i') && format->v.ll < 0) {
        value = -value;
    }
    if (value != 0 || format->prec != 0) {
        buffer[--index] = digits[value % base];
    }
    format->v.ll = value / base;
    while (format->v.ll > 0 && index > 0) {
        LongLongDiv result = func_8005EF50(format->v.ll, base);

        format->v.ll = result.quot;
        buffer[--index] = digits[result.rem];
    }
    format->n1 = 24 - index;
    func_8005A530(format->s, buffer + index, format->n1);
    if (format->n1 < format->prec) {
        format->nz0 = format->prec - format->n1;
    }
    if (format->prec < 0 && (format->flags & 0x14) == 0x10) {
        if ((index = format->width - format->n0 - format->nz0 - format->n1) > 0) {
            format->nz0 += index;
        }
    }
}
