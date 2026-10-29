extern unsigned char D_80072AF8;
extern unsigned char D_80137D69;
extern int func_80038C18(int);
extern unsigned int func_80038E0C(int);
extern int func_8003C3C4(int);

int func_8003C2F8(void) {
    unsigned int m;
    unsigned int t;

    if (D_80072AF8 == 0) {
        return 0;
    }
    D_80137D69 = 0;
    func_80038C18(0);
    m = func_80038E0C(0);
    t = func_80038E0C(1);
    if (t < m) m = t;
    t = func_80038E0C(2);
    if (t < m) m = t;
    t = func_80038E0C(3);
    if (t < m) m = t;
    m = m - 1;
    if ((int)m < 0) m = 0;
    if ((int)m >= 11) m = 10;
    return func_8003C3C4(m);
}
