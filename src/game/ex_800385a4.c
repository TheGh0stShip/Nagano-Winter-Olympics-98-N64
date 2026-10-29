typedef struct Timer {
    unsigned char pad0[0x28];
    unsigned long long value;
    unsigned char pad30[8];
} Timer;

extern unsigned char D_80072AF8;
unsigned char D_80137870;
unsigned char D_80137871;
unsigned char pad_80137872;
unsigned char pad_80137873;
unsigned char pad_80137874;
unsigned char pad_80137875;
unsigned char pad_80137876;
unsigned char pad_80137877;
unsigned long long D_80137878;
unsigned long long D_80137880;
unsigned long long D_80137888;
float D_80137890;
float D_80137894;
unsigned long long D_80137898;
unsigned long long D_801378A0;
short D_801378A8;
short pad_801378AA;
short pad_801378AC;
short pad_801378AE;
Timer D_801378B0;
Timer D_801378E8;
unsigned long long pad_80137920[12];
unsigned long long D_80137980;
unsigned long long pad_80137988[13];
unsigned long long D_801379F0;
unsigned long long pad_801379F8[89];
unsigned long long D_80137CC0;
unsigned long long pad_80137CC8[37];
unsigned int pad_80137DF0;
unsigned char D_80137DF4;
extern char D_80137920[];
extern char D_80137A70[];
extern char D_80137B40[];
extern char D_80137C10[];
extern char D_80137D70[];
extern char D_80137D98[];
extern char D_80137DC0[];
extern char D_80137C70[];
extern char D_80137CD0[];
extern unsigned long long D_8007C990;
extern unsigned long long func_8005B340(void);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);
extern unsigned long long func_8004F088(unsigned long long a, unsigned long long b);
extern void func_800377E8(void *record, float x, float y);
extern void func_80036F40(void *record, float value);
extern void func_80037D94(void *record);
extern void func_80038828(void *record);
extern void func_80039788(void);

void func_800385A4(void) {
    int pad[6];
    unsigned long long time;

    if (D_80072AF8) {
        if (D_80137870 == 1) {
            if (D_801378A8 == 0) {
                D_80137880 = func_8004EF88(func_8004F088(func_8004EF88(func_8005B340(), 1000), 1000000), D_8007C990);
            }
            if (D_80137871 == 1) {
                D_80137888 = D_80137880;
                D_80137890 = D_80137894;
            }
        }
        time = D_80137880;
        if (D_80137DF4 == 1) {
            D_80137890 = D_80137894;
        }
        D_801378B0.value = D_80137878;
        D_801378E8.value = time;
        D_801379F0 = D_80137888;
        D_80137CC0 = time;
        D_80137980 = D_80137898;
        func_800377E8(&D_801378B0, 0.0f, 0.0f);
        func_800377E8(&D_801378E8, 0.0f, 0.0f);
        func_80036F40(D_80137920, D_80137890);
        func_80037D94(D_80137A70);
        func_80037D94(D_80137B40);
        func_80037D94(D_80137C10);
        func_80037D94(D_80137D70);
        func_80037D94(D_80137D98);
        func_80037D94(D_80137DC0);
        func_80037D94(D_80137C70);
        func_80037D94(D_80137CD0);
        func_80038828(&D_801378B0);
        func_80038828(&D_801378E8);
        func_80039788();
    }
}
