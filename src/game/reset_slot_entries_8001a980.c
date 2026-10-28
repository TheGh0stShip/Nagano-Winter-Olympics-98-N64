typedef struct Mark {
    unsigned char active;
    unsigned char pad1;
    short x;
    short y;
    short z;
    short timer;
} Mark;

extern short D_80136420[];
extern short D_80136418[];
extern unsigned char D_80136190[];
extern unsigned char D_80136194[];
extern Mark D_80136198[][16];

void func_8001A980(unsigned char index) {
    unsigned char i;

    D_80136420[index] = 0;
    D_80136418[index] = 0;
    D_80136190[index] = 0;
    D_80136194[index] = 0;
    for (i = 0; i < 16; i++) {
        D_80136198[index][i].active = 0;
        D_80136198[index][i].x = 0;
        D_80136198[index][i].y = 0;
        D_80136198[index][i].z = 0;
        D_80136198[index][i].timer = 0;
    }
}

void func_8001AA14(unsigned char index) {
    if (D_80136190[index] >= 16) {
        D_80136190[index] = 0;
    }
}
