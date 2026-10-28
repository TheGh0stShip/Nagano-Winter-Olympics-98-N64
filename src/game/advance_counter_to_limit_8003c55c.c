extern int func_8003BAD0(int id, int arg1);
extern int func_8003C498(int handle, signed char arg1, int arg2, int arg3);
extern void func_8002BAEC(void);
extern signed char D_8013821A;
extern unsigned char D_80137D69;

void func_8003C55C(void) {
    int result = func_8003C498(func_8003BAD0(25, 1), D_8013821A, 6, -36);

    if (D_80137D69 < 40) {
        if (++D_80137D69 == 40) {
            func_8002BAEC();
        }
    }
}
