typedef struct Channel {
    unsigned int word;
    unsigned char pad4[0x8];
    unsigned char kind;
    unsigned char index;
    unsigned char pad[0x4A];
    unsigned short volume;
    unsigned char pad5A;
    unsigned char flag;
} Channel;

extern Channel *D_80179924;
extern unsigned char *D_80179920;
extern unsigned char *D_80073B80[];
extern unsigned char D_80073F88[];
extern void func_8004BC04(unsigned char *data, int kind);

void func_8004BB30(void) {
    unsigned int volume;
    unsigned char *table;
    int kind;

    volume = D_80179924->word & 0x7F0000;
    if (volume != 0) {
        volume >>= 8;
        if (volume < 0xA00) {
            volume = 0xA00;
        } else if (volume >= 0x7501) {
            volume = 0x7500;
        }
        D_80179924->flag = 0;
        D_80179924->volume = volume | 0x8000;
    }
    D_80179924->index = *D_80179920;
    D_80179920++;
    kind = D_80179924->kind;
    if (kind < 2) {
        table = D_80073B80[kind];
        table += D_80179924->index * 7;
    } else {
        table = D_80073F88;
    }
    func_8004BC04(table, kind);
}
