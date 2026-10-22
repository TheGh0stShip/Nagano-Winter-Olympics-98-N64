extern void *D_80136704;
extern void func_8000B924(void);
void func_8001DD68(void) {
    if (D_80136704 != 0) {
        func_8000B924();
        D_80136704 = 0;
    }
}
