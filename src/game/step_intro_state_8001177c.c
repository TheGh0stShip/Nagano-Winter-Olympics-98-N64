extern unsigned short D_80134090;
extern void func_8003C768(void);
extern void func_8003CA38(void);
extern int func_80039788(void);

signed char func_8001177C(void) {
    signed char done = 0;

    switch (D_80134090) {
        case 0:
            D_80134090 = 10;
            func_8003C768();
            func_8003CA38();
            break;
        case 10:
            if (func_80039788() == 1) {
                D_80134090 = 20;
            }
            break;
        case 20:
            done = 1;
            break;
        default:
            D_80134090 = 0;
            break;
    }
    return done;
}
