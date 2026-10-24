typedef struct PiAccessRecord {
    unsigned char pad_00[0x10];
    unsigned short state;
} PiAccessRecord;

extern PiAccessRecord *D_8007C950;
extern unsigned char D_8007C948;
extern int func_8005BFD0(void);
extern void func_8004F80C(void *queue);
extern void func_8005BFF0(int mask);

void func_8005DC80(void) {
    register int mask = func_8005BFD0();

    D_8007C950->state = 2;
    func_8004F80C(&D_8007C948);
    func_8005BFF0(mask);
}
