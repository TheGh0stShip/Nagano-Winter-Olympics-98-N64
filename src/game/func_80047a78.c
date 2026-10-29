typedef struct Message {
    short type;
    short pad;
    int value;
} Message;

extern unsigned char D_8008C650[];
extern unsigned char D_80138888[];
extern unsigned char D_801389A0[];
extern unsigned char D_80138AB8[];
extern int D_801386C0[];
extern unsigned int D_80073680;

extern void func_80003F60(void *a, void *b, void *c);
extern int func_8004E540(void *queue, Message **msg, int block);
extern int func_80047BC0(int a, int b);
extern void func_80047D6C(int a);
extern void func_8004E774(void *a);

void func_80047A78(int unused) {
    unsigned done;
    int sel;
    Message *msg;
    unsigned char info[0x0C];

    done = 0;
    sel = 0;
    func_80003F60(D_8008C650, info, D_80138888);
    do {
        func_8004E540(D_80138888, &msg, 1);
        switch (msg->type) {
        case 4:
            break;
        case 1:
            if (func_80047BC0(D_801386C0[D_80073680 % 3 + 2], sel) != 0) {
                func_8004E540(D_801389A0, &msg, 1);
                func_80047D6C(msg->value);
                sel = msg->value;
            }
            break;
        case 0x20:
            done = 1;
            break;
        }
    } while (!done);
    func_8004E774(D_80138AB8);
}
