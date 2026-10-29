typedef struct StreamState {
    unsigned char count;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char pad5[3];
    unsigned int *table;
    unsigned short h0C;
    unsigned short h0E;
    unsigned char b10;
} StreamState;

extern unsigned char D_80074680[][2];
extern StreamState D_80179688;
extern unsigned int D_80179700[];
extern unsigned int D_801796F8;
extern unsigned short D_8018D680[];
extern void func_80049B48(void);

void func_80049A78(unsigned short id, unsigned char value) {
    unsigned char *entry = D_80074680[(unsigned short)(id - 16)];
    int n;
    unsigned int off = (unsigned int)D_8018D680;

    D_80179688.count = entry[0];
    D_80179688.b3 = entry[1];
    D_80179688.table = D_80179700;
    for (n = 0; n < D_80179688.count; n++) {
        D_80179700[n] = D_8018D680[n] + off;
    }
    D_801796F8 = id;
    D_80179688.b1 = 0;
    D_80179688.b2 = 30;
    D_80179688.h0C = 0;
    D_80179688.h0E = 0;
    D_80179688.b10 = 0;
    D_80179688.b4 = value;
    func_80049B48();
}
