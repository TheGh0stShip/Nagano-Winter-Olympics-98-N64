typedef struct ContStatus {
    unsigned short type;
    unsigned char status;
    unsigned char errnum;
} ContStatus;

typedef struct Pfs {
    unsigned char pad[0x68];
} Pfs;

extern unsigned char D_80130BE0[];
extern ContStatus D_80130C00[];
extern Pfs D_80135790[];
extern unsigned char D_80135930[];
extern int osPfsInitPak(void *, Pfs *, int);

int func_80013934(void) {
    unsigned char i;
    unsigned short mask;

    for (i = 0; i < 4; i++) {
        if (D_80130C00[i].status & 1) {
            if (osPfsInitPak(D_80130BE0, &D_80135790[i], i) == 0) {
                D_80135930[i] = 0;
            } else {
                D_80135930[i] = 1;
                mask |= 1 << i;
            }
        } else {
            D_80135930[i] = 1;
        }
    }
    return 0;
}
