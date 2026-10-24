extern float D_801366EC;
extern void func_8001DF00(unsigned int first, unsigned int second);
extern void func_8001E020(unsigned int first, unsigned int second);
extern void func_8001DFC0(unsigned int index, float x, float y);
extern void func_8001DD08(void);

int func_8001D414(void) {
    func_8001DF00(4, 0);
    func_8001E020(0, 1);
    func_8001DFC0(0, 0.0f, 0.0f);
    D_801366EC = 0.0f;
    func_8001DD08();
    return 1;
}
