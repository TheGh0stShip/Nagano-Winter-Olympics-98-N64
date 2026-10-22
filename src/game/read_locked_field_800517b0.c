typedef struct FieldRecord {
    int pad;
    int value;
} FieldRecord;

extern FieldRecord *D_8007DA94;
extern int func_8005BFD0(void);
extern void func_8005BFF0(int);

int func_800517B0(void) {
    register int lock = func_8005BFD0();
    int result = D_8007DA94->value;

    func_8005BFF0(lock);
    return result;
}
