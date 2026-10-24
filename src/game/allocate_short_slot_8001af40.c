extern signed short D_80136430[][50];

unsigned char func_8001AF40(unsigned char index) {
    unsigned char slot = 255;
    unsigned char i;

    for (i = 0; i < 50; i++) {
        if (D_80136430[index][i] == 0) {
            slot = i;
            break;
        }
    }
    if (slot == 255) {
        for (i = 0; i < 50; i++) {
            D_80136430[index][i] = 0;
        }
        slot = 0;
    }
    return slot;
}
