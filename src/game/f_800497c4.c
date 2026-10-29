typedef struct Channel {
    int active;
    unsigned char prio;
    unsigned char pad[0xCB];
} Channel;

extern Channel D_8018C980[];
extern unsigned char D_8018D004;

unsigned char func_800497C4(unsigned char flag) {
    unsigned char i;
    unsigned char idx;
    unsigned char best;
    unsigned char j;

    if (flag == 1) {
        idx = 8;
        best = D_8018D004;
        for (i = 9; i < 16; i++) {
            if (D_8018C980[i].prio <= best) {
                idx = i;
                best = D_8018C980[i].prio;
            }
        }
    } else {
        idx = 14;
        best = 255;
        for (i = 14; i >= 8; i -= 2) {
            j = i;
            if (D_8018C980[i].prio < D_8018C980[j + 1].prio) {
                j++;
            }
            if (D_8018C980[j].prio <= best) {
                idx = i;
                best = D_8018C980[j].prio;
            }
        }
    }
    return idx;
}
