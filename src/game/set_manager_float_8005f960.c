typedef struct ManagerRecord {
    unsigned short state;
    unsigned char pad_02[0x22];
    float value;
} ManagerRecord;

extern ManagerRecord *D_8007DA94;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_8005F960(float value) {
    register unsigned int mask = func_8005BFD0();

    D_8007DA94->value = value;
    D_8007DA94->state |= 4;
    func_8005BFF0(mask);
}
