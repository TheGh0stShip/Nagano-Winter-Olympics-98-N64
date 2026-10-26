extern signed short D_80136430[4][50];

void func_8001AEE0(void) {
    unsigned char group;
    unsigned char slot;

    for (group = 0; group < 4; group++) {
        for (slot = 0; slot < 50; slot++) {
            D_80136430[group][slot] = 0;
        }
    }
}
