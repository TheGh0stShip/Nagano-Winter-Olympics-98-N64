typedef struct Template {
    unsigned int words[0x1E];
} Template;

extern unsigned char *D_80126BF0;
extern int D_80071CEC[];
extern Template D_8006E510;
extern void func_80006EE0(int mode, int value);
extern void func_8002D304(void);
extern void func_8002D394(void);
extern void func_80012788(void);

int func_8002D200(void) {
    func_80006EE0(0x38, D_80071CEC[D_80126BF0[0x977EC]]);
    *(Template *)(D_80126BF0 + 0x7FBA0) = D_8006E510;
    func_8002D304();
    func_8002D394();
    func_80012788();
    return 0;
}
