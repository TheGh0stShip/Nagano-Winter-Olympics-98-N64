typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

typedef struct RuntimeTextState {
    u8 pad00[0x190];
    float values190[16];
} RuntimeTextState;

extern RuntimeTextState D_80137150;
extern u8 D_801374B2;
extern s8 D_80071A50[];
extern void func_8002B228(u8 first, u8 second);

void func_8002B0FC(u8 start, u8 end) {
    u16 outer;
    u16 i;
    float multiplier;
    float current;
    float next;

    for (outer = start; outer < end; outer++) {
        for (i = start; i < end - outer; i++) {
            multiplier = D_80071A50[D_801374B2];
            current = multiplier;
            current *= D_80137150.values190[i];
            next = multiplier;
            next *= D_80137150.values190[i + 1];
            if (next < current) {
                func_8002B228(i, i + 1);
            }
        }
    }
}
