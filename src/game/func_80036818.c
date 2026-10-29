extern unsigned char D_801378B0[];
extern unsigned char D_801378E8[];
extern unsigned char D_80137A70[];
extern unsigned char D_80137A98[];
extern unsigned char D_80137AD0[];
extern unsigned char D_80137B08[];
extern unsigned char D_80137B40[];
extern unsigned char D_80137B68[];
extern unsigned char D_80137BA0[];
extern unsigned char D_80137BD8[];
extern unsigned char D_80137C10[];
extern unsigned char D_80137C38[];
extern unsigned char D_80137A00[];
extern unsigned char D_80137C70[];
extern unsigned char D_80137C98[];
extern unsigned char D_80137CD0[];
extern unsigned char D_80137CF8[];
extern unsigned char D_80137D30[];
extern unsigned char D_80137990[];
extern unsigned char D_80137D98[];
extern unsigned char D_801379C8[];
extern unsigned char D_80137D70[];
extern unsigned char D_80137958[];
extern unsigned char D_80137DC0[];
extern unsigned char D_80137920[];
extern unsigned char D_80137A38[];
extern unsigned char D_06002358[];
extern unsigned char D_06002338[];
extern unsigned char D_06002370[];
extern unsigned char D_06002380[];
extern unsigned char D_060086D8[];
extern int D_80072AEC;
extern int D_80072AF0;
extern float D_80080514;




long long D_80137880;
long long D_80137888;
int D_80137890;
float D_80137894;
long long D_80137898;
int D_801378A0;
int D_801378A4;
short D_801378A8;
extern unsigned char D_80137DF4;
extern unsigned char D_80137DE8;

extern void func_80039250(void);
extern int func_80036740(int *table);
extern short func_80037040(void);
extern void func_800376C0(void *orbit, int target, unsigned short kind, float angle, float distance, float height);
extern void func_80037AA0(void *camera, int target, float yaw, float pitch, int mode);
extern void func_80037760(void *desc, int index, float first, float second, void *first_word, void *second_word);
extern void func_80037B00(void *object, void *value);
extern void func_80037B08(void *object, void *value);
extern void func_80036F40(void *object, float value);
extern void func_80036ED0(int source);
extern void func_8003B020(void);
extern void func_80037348(void);
extern void func_80036648(float value);

int func_80036818(void) {
    int result;
    int slots[10];
    short kind;
    int i;

    func_80039250();
    for (i = 0; i < 10; i++) {
        slots[i] = -2;
    }
    result = func_80036740(slots);
    kind = func_80037040();
    func_800376C0(D_801378B0, slots[0], (unsigned short)(kind | 0x10), -44.0f, 81.0f, 3.0f);
    func_800376C0(D_801378E8, slots[1], kind, -44.0f, 58.0f, 4.0f);
    func_8003B020();
    func_80037AA0(D_80137A70, 0x29, 202.0f, -47.0f, 0);
    func_800376C0(D_80137A98, 0x2A, 0x830, -176.0f, -1.0f, 7.0f);
    func_80037B00(D_80137A70, D_80137A98);
    func_80036F40(D_80137A98, 1.0f);
    func_80037760(D_80137AD0, 0x2B, -180.0f, -1.0f, (void *)D_80072AEC, D_06002358);
    func_80037B08(D_80137A98, D_80137AD0);
    func_800376C0(D_80137B08, 0x2C, kind, -74.0f, -1.0f, 8.0f);
    func_80037B08(D_80137AD0, D_80137B08);
    func_80037AA0(D_80137B40, 0x2D, 202.0f, -63.0f, 0);
    func_800376C0(D_80137B68, 0x2E, 0x830, -176.0f, -1.0f, 7.0f);
    func_80037B00(D_80137B40, D_80137B68);
    func_80036F40(D_80137B68, 2.0f);
    func_80037760(D_80137BA0, 0x2F, -177.0f, -1.0f, (void *)D_80072AEC, D_06002338);
    func_80037B08(D_80137B68, D_80137BA0);
    func_800376C0(D_80137BD8, 0x30, kind, -74.0f, -1.0f, 9.0f);
    func_80037B08(D_80137BA0, D_80137BD8);
    func_80037AA0(D_80137C10, 0x31, 202.0f, -90.0f, 1);
    func_80037760(D_80137C38, 0x32, -176.0f, 11.0f, (void *)D_80072AEC, D_06002370);
    func_80037B00(D_80137C10, D_80137C38);
    func_800376C0(D_80137A00, 0x33, kind, -74.0f, 11.0f, 10.0f);
    func_80037B08(D_80137C38, D_80137A00);
    func_80037AA0(D_80137C70, 0x34, 202.0f, -74.0f, 1);
    func_800376C0(D_80137C98, 0x35, kind, -66.0f, 9.0f, 11.0f);
    func_80037B00(D_80137C70, D_80137C98);
    func_80037AA0(D_80137CD0, 0x36, 202.0f, -90.0f, 1);
    func_80037760(D_80137CF8, 0x37, -172.0f, 11.0f, (void *)D_80072AF0, D_060086D8);
    func_80037B00(D_80137CD0, D_80137CF8);
    func_800376C0(D_80137D30, 0x38, 0x820, -94.0f, 11.0f, 7.0f);
    func_80037B08(D_80137CF8, D_80137D30);
    func_80036F40(D_80137D30, 1234.0f);
    func_800376C0(D_80137990, slots[7], 0, 0.8f, D_80080514, 7.0f);
    func_80036ED0(0);
    func_80037AA0(D_80137D98, -1, 229.0f, -94.0f, 1);
    func_800376C0(D_801379C8, 0x1C, kind, -101.0f, 0.0f, 6.0f);
    func_80037B00(D_80137D98, D_801379C8);
    func_80037AA0(D_80137D70, 0x23, 229.0f, -90.0f, 1);
    func_800376C0(D_80137958, 0x27, kind, -101.0f, 11.0f, 5.0f);
    func_80037B00(D_80137D70, D_80137958);
    func_80037AA0(D_80137DC0, 0x24, 229.0f, -74.0f, 1);
    func_800376C0(D_80137920, 0x26, 0x930, -127.0f, 9.0f, 7.0f);
    func_80037B00(D_80137DC0, D_80137920);
    func_80037760(D_80137A38, 0x28, -119.0f, 9.0f, (void *)D_80072AEC, D_06002380);
    func_80037B08(D_80137920, D_80137A38);
    func_80037348();
    func_80036648(0.0f);
    D_80137898 = 600000;
    D_80137880 = 0;
    D_80137888 = 0;
    D_801378A8 = 0;
    D_80137DF4 = 0;
    D_80137DE8 = 0;
    if (result < 2) {
        return -1;
    }
    return 0;
}
