typedef struct IoMessage {
    unsigned char data[0x18];
} IoMessage;

extern void func_8005A600(void *address, int size);
extern void func_8005A6B0(void *address, int size);
extern void func_800550F0(IoMessage *message, int priority, int direction, unsigned int devAddr, void *vAddr, int size, void *queue);
extern void func_8004E540(void *queue, void *message, int flags);
extern unsigned char D_8008C4F0[];

void func_800015C4(unsigned int devAddr, void *vAddr, int size) {
    IoMessage message;
    void *dummy = 0;

    func_8005A600(vAddr, size);
    func_8005A6B0(vAddr, size);
    func_800550F0(&message, 0, 0, devAddr, vAddr, size, D_8008C4F0);
    func_8004E540(D_8008C4F0, &dummy, 1);
}
