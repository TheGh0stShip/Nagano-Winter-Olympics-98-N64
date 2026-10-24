extern unsigned int func_8005DB30(void);
extern unsigned int D_8007368C;
extern unsigned int D_8007368C_write;

/* LDSYM D_8007368C_write=0x8007368C */

void func_80047D6C(int unused) {
    if ((func_8005DB30() >> 2) == 0) {
        if (D_8007368C == 0) {
            D_8007368C_write = 0;
        }
    }
}
