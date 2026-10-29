extern unsigned char *D_80126BF0;
extern int D_80136C84;
extern int D_80133558;
extern int D_80133580;
extern int D_801330D0;
extern void func_800485AC(int arg0);

int func_8000C5E4(void) {
    unsigned char *base = D_80126BF0 + 0x78000;
    unsigned short buttons;

    buttons = *(unsigned short *)(base + 0x48F8) | *(unsigned short *)(base + 0x4906) |
              *(unsigned short *)(base + 0x4914) | *(unsigned short *)(base + 0x4922);
    if ((buttons & 0x1000) && D_80136C84 == 0) {
        if (D_80133558 == 1) {
            D_80133558 = 2;
        } else if (D_80133558 >= 2) {
            D_80133580 = 0x30;
            func_800485AC(7);
        }
    }
    if (D_80133558 == 5) {
        D_801330D0 = 0;
        return 0;
    }
    return 1;
}
