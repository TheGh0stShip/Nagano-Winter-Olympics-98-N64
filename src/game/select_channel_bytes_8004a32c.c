extern int D_801796F8;
extern unsigned char D_80179671;
extern unsigned char D_80179672;
extern unsigned char D_80179673;
extern unsigned char D_80179674;
extern unsigned char D_80179675;
extern unsigned char D_80179676;
extern unsigned char D_800737E1[];

void func_8004A32C(void) {
    if (D_801796F8 != 10) {
        if (D_80179673 == 0) {
            D_80179673 = 0xFF;
        }
        D_80179672 = D_80179671 = D_800737E1[D_801796F8];
    } else {
        if (D_80179676 == 0) {
            D_80179676 = 0xFF;
        }
        D_80179675 = D_80179674 = D_800737E1[D_801796F8];
    }
}
