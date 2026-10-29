extern signed char D_80071F30;
extern unsigned char D_80071F3C;
extern unsigned char D_80137566[];

void func_8003070C(void) {
    short i;
    short value;
    unsigned char amount = D_80071F3C;

    switch (D_80071F30) {
    case 1:
        for (i = 3; i < 0x40; i += 4) {
            value = D_80137566[i];
            value += amount;
            if (value >= 0x100) {
                value = 0xFF;
            }
            D_80137566[i] = value;
        }
        break;
    case 3:
        for (i = 3; i < 0x40; i += 4) {
            value = D_80137566[i];
            value += amount;
            if (value >= 0x100) {
                value = 0xFF;
            }
            D_80137566[i] = value;
        }
        break;
    case 2:
        for (i = 3; i < 0x40; i += 4) {
            value = D_80137566[i];
            value -= amount;
            if (value < 0) {
                value = 0;
            }
            D_80137566[i] = value;
        }
        break;
    case 4:
        for (i = 3; i < 0x40; i += 4) {
            value = D_80137566[i];
            value -= amount;
            if (value < 0) {
                value = 0;
            }
            D_80137566[i] = value;
        }
        break;
    case 5:
        break;
    }
}
