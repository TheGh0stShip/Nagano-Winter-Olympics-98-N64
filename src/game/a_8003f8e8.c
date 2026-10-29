extern unsigned short D_80138228;
extern signed char D_80138220[];

int func_8003F8E8(unsigned char flag) {
    int ret = 0;
    int found;
    short i;

    if (flag == 0) {
        D_80138228 = 0;
        return 0;
    }
    D_80138228++;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (flag == 1) {
            if (D_80138220[i * 2 + 1] > 0 && D_80138220[i * 2 + 1] < 3) {
                if (D_80138228 % 6 == 0) {
                    D_80138220[i * 2 + 1]++;
                }
                found = 1;
            }
        } else {
            if (D_80138220[i * 2 + 1] >= 2) {
                if (D_80138228 % 6 == 0) {
                    D_80138220[i * 2 + 1]--;
                }
                found = 1;
            }
        }
    }
    if (D_80138228 % 6 >= 3 && !found) {
        ret = 1;
        D_80138228 = 0;
    }
    return ret;
}
