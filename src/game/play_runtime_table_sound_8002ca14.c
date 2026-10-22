extern unsigned char *D_80126BF0;
extern unsigned char D_80071C50[];
extern unsigned short D_80071C5C[][6];
extern void func_80048580(unsigned short);

void func_8002CA14(unsigned char index) {
    unsigned char row = D_80071C50[D_80126BF0[0x977EC]];
    unsigned short sound = D_80071C5C[row][index];

    if (sound != 0xFFFF) {
        func_80048580(sound);
    }
}
