typedef struct FourWords {
    int values[4];
} FourWords;

extern unsigned char D_80137555;
extern FourWords D_80071E54[];
extern FourWords D_80137528;

void func_8002E7C0(void) {
    D_80137528 = D_80071E54[D_80137555];
}
