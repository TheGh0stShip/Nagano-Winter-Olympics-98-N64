typedef struct InitBlock {
    int words[30];
} InitBlock;

extern unsigned char *D_80126BF0;
extern InitBlock D_8006E510;
extern unsigned char D_80072AFC;
extern unsigned char D_80138214;
extern unsigned char D_80138218;
extern signed char D_8013821A;
extern float D_80138200;

extern void func_80039A8C(void);
extern void func_80039128(int);
extern void func_80038E88(int);
extern void func_8003A120(void);
extern void func_8003E75C(int *kind, int *offset);
extern int func_8003B5F4(int);
extern int func_8003B694(int, int);
extern void func_8003A5C8(int, int, int);
extern void func_8003E904(void);

int func_8003E63C(int mode) {
    int pad[3];
    int kind;
    int offset;
    int result;

    kind = 1;
    *(InitBlock *)(D_80126BF0 + 0x800C8) = D_8006E510;
    func_80039A8C();
    D_80072AFC = mode;
    func_80039128(-1);
    func_80038E88((D_80126BF0 + 0x90000)[0x77EC]);
    D_80138218 = 0;
    D_80138214 = 0;
    func_8003A120();
    func_8003E75C(&kind, &offset);
    if ((D_80126BF0 + 0x90000)[0x77F1] == 21) {
        result = func_8003B5F4(25);
    } else {
        result = func_8003B694(25, 0);
    }
    func_8003A5C8(result, D_8013821A, kind);
    D_80138200 = 0.0f;
    func_8003E904();
    return 0;
}
