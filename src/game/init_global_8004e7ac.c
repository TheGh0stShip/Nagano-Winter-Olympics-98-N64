extern void *D_8007C910;
extern void func_800557A0(void);
void func_8004E7AC(void *value) {
    if (D_8007C910 == 0) {
        D_8007C910 = value;
        func_800557A0();
    }
}
