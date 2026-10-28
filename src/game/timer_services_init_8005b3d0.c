typedef struct Timer {
    struct Timer *next;
    struct Timer *prev;
    unsigned long long interval;
    unsigned long long value;
    void *mq;
    void *msg;
} Timer;

unsigned long long D_80194260;
extern unsigned int D_80194268;
extern unsigned int D_8019426C;
extern Timer *D_8007DA20;

void func_8005B3D0(void) {
    D_80194260 = 0;
    D_80194268 = 0;
    D_8019426C = 0;
    D_8007DA20->next = D_8007DA20->prev = D_8007DA20;
    D_8007DA20->interval = D_8007DA20->value = 0;
    D_8007DA20->mq = 0;
    D_8007DA20->msg = 0;
}
