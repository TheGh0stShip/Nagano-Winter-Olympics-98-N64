typedef struct ManagerRecord {
    unsigned short state;
    unsigned short mode;
    unsigned char pad_04[0x0C];
    void *field_10;
    void *field_14;
} ManagerRecord;

extern ManagerRecord *D_8007DA94;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_8005C840(void *field_10, void *field_14, unsigned int mode) {
    register unsigned int mask = func_8005BFD0();

    D_8007DA94->field_10 = field_10;
    D_8007DA94->field_14 = field_14;
    D_8007DA94->mode = mode;
    func_8005BFF0(mask);
}
