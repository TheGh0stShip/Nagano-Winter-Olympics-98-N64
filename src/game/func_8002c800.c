extern unsigned char D_801374D0[];
extern unsigned char D_801374D8[];
extern int func_8002C934(unsigned short a, unsigned char index);
extern int func_8002CA88(unsigned short a, unsigned char index);
extern int func_8002CB28(unsigned short a, unsigned char index);
extern void func_8002CCB8(unsigned short a, unsigned char index);

int func_8002C800(unsigned char index) {
    unsigned char value = D_801374D0[index];
    int result;

    switch (D_801374D8[index]) {
    case 0:
        result = 0;
        if (func_8002C934(value, index) != 0) {
            (D_801374D8[index])++;
        }
        break;
    case 1:
        result = 1;
        if (func_8002CA88(value, index) != 0) {
            (D_801374D8[index])++;
        }
        break;
    case 2:
        result = 2;
        if (func_8002CB28(value, index) != 0) {
            (D_801374D8[index])++;
        }
        break;
    default:
        result = 3;
        func_8002CCB8(value, index);
        break;
    }
    return result;
}
