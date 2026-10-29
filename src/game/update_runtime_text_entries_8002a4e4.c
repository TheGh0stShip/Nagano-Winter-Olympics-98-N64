typedef unsigned char u8;
typedef unsigned short u16;

typedef struct RuntimeTextState {
    u8 names[16][9];
    u8 flags90[16];
    u8 valuesA0[16][7];
    u8 values110[16][7];
    u8 flags180[16];
} RuntimeTextState;

extern u8 *D_80126BF0;
extern RuntimeTextState D_80137150;
extern u8 D_801373A0[];
extern void func_8002A5E8(u8 value, u8 *output);
extern void func_8000F04C(u8 *name, u8 flag, u8 *output, u8 *table);
extern void func_8002810C(void);

void func_8002A4E4(void) {
    u8 output[12];
    u16 i;

    if (D_80126BF0[0x977F0] == D_80126BF0[0x977EF] + 1) {
        if (D_80126BF0[0x977EC] == 0) {
            for (i = 0; i < 16; i++) {
                if (D_80137150.flags180[i] != 0) {
                    func_8002A5E8(D_80137150.flags180[i] - 1, output);
                    output[7] = i;
                    func_8000F04C(D_80137150.names[i],
                                  D_80137150.flags90[i], output,
                                  &D_801373A0[D_80137150.flags180[i] * 7 +
                                               0x9B]);
                }
            }
            func_8002810C();
        }
    }
}
