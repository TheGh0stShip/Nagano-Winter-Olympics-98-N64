typedef struct ContStatus {
    unsigned short type;
    unsigned char status;
    unsigned char errnum;
} ContStatus;

typedef struct PortRecord {
    unsigned char data[0xE];
} PortRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80130BE0[];
extern ContStatus D_80130C00[];
extern void func_80059620(void *);
extern void func_8004E540(void *, void *, int);
extern void func_800596A4(void *);

void func_80043B58(void) {
    short i;

    func_80059620(D_80130BE0);
    func_8004E540(D_80130BE0, 0, 1);
    func_800596A4(D_80130C00);
    for (i = 0; i < 4; i++) {
        if (!(D_80130C00[i].errnum & 8)) {
            *(unsigned short *)(D_80126BF0 + 0x7C8F4 + i * sizeof(PortRecord)) = 1;
        } else {
            *(unsigned short *)(D_80126BF0 + 0x7C8F4 + i * sizeof(PortRecord)) = 0;
        }
    }
}
