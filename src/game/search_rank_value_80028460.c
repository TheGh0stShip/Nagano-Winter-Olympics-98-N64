typedef struct Ranking {
    unsigned char pad[0x190];
    float limits[16];
} Ranking;

extern Ranking D_80137150;
extern void func_80028504(unsigned char index);
extern float func_800289B4(unsigned short index);
extern float func_80029198(float value);

float func_80028460(unsigned char index) {
    float value;
    unsigned char i;

    func_80028504(index);
    for (i = 0; i < 10; i++) {
        value = D_80137150.limits[index] + func_800289B4(index);
        if (func_80029198(value) == value) {
            return value - D_80137150.limits[index];
        }
    }
    return value - D_80137150.limits[index];
}
