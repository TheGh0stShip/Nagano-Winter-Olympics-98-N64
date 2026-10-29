typedef unsigned char u8;
typedef signed char s8;

typedef struct RuntimeFloatTable {
    u8 pad000[0x190];
    float values[256];
} RuntimeFloatTable;

extern u8 *D_80126BF0;
extern u8 D_801374B2;
extern s8 D_80071A50[];
extern RuntimeFloatTable D_80137150;
extern int func_8002B5D0(int);
extern void func_8002B624(void);

int func_8002B4E4(void) {
    struct {
        u8 pad[6];
        u8 current;
    } state;
    u8 count;
    u8 index;
    long long unused;
    float scale;
    float threshold;
    float product;

    state.current = func_8002B5D0(D_80126BF0[0x977EF]);
    count = 0;
    func_8002B624();
    scale = D_80071A50[D_801374B2];
    threshold = scale;
    threshold *= D_80137150.values[state.current];
    for (index = 0; index <= state.current; index++) {
        product = scale;
        product *= D_80137150.values[index];
        if (product < threshold) {
            count++;
        }
    }
    return count;
}
