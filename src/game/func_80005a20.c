typedef struct ContStatus {
    unsigned short type;
    unsigned char status;
    unsigned char errnum;
} ContStatus;

typedef struct MesgQueue {
    void *mtqueue;
    void *fullqueue;
    int validCount;
    int first;
    int msgCount;
    void *msg;
} MesgQueue;

typedef struct PortRecord {
    unsigned char data[0xE];
} PortRecord;

extern unsigned char *D_80126BF0;
extern ContStatus D_80130C00[];
extern unsigned char D_80130BE0[];
extern unsigned char D_80130BF8[];
extern void func_8005A5D0(void *, void *, int);
extern void func_80059390(int, void *, int);
extern int func_80050610(void *, unsigned char *, ContStatus *);

void func_80005A20(void) {
    MesgQueue queue;
    void *message;
    short i;
    unsigned char pattern;

    func_8005A5D0(&queue, &message, 1);
    func_80059390(5, &queue, 1);
    func_80050610(&queue, &pattern, D_80130C00);
    func_8005A5D0(D_80130BE0, D_80130BF8, 1);
    func_80059390(5, D_80130BE0, 0);
    for (i = 0; i < 4; i++) {
        if ((pattern & (1 << i)) && !(D_80130C00[i].errnum & 8)) {
            *(unsigned short *)(D_80126BF0 + 0x7C8F4 + i * sizeof(PortRecord)) = 1;
        } else {
            *(unsigned short *)(D_80126BF0 + 0x7C8F4 + i * sizeof(PortRecord)) = 0;
        }
    }
}
