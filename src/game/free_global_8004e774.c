extern void *D_8007C910;
extern void func_8005FE50(void);
void func_8004E774(void) {
    if (D_8007C910 != 0) {
        func_8005FE50();
        D_8007C910 = 0;
    }
}
