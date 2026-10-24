extern unsigned char *D_80126BF0;

void func_8002BC80(unsigned short *value, unsigned char reduced) {
    if (((0x980 >> D_80126BF0[0x977EC]) & 1) != 0) {
        *value = 0x40A;
    } else {
        *value = 0x30A;
    }
    if (reduced != 0) {
        *value -= 10;
    }
}
