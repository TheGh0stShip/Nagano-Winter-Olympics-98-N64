extern unsigned char D_80072AFC;
extern unsigned char D_80138214;
extern unsigned char D_801380C0[];
typedef struct State {
    unsigned char pad[0x977EC];
    unsigned char mode;
    unsigned char pad2[3];
    unsigned char flag;
} State;

extern State *D_80126BF0;
extern void *D_80138210;

extern void func_8003DFA8(void);
extern void *func_8002A88C(void);
extern void func_8003E078(void *);
extern void func_80027CEC(void);
extern void func_8000ECBC(unsigned char, void *);
extern void func_8003E2C4(void *);
extern void func_8000ED18(void *);
extern void func_8003E458(void *);

void func_80038E88(int arg) {
    unsigned char buf[0x9C];

    func_8003DFA8();
    if (D_80072AFC > 0) {
        D_80138210 = func_8002A88C();
        func_8003E078(D_80138210);
    } else {
        switch (D_80138214) {
        case 0:
            if (D_80126BF0->flag <= 0) {
                D_80126BF0->flag = 1;
            }
            if (D_80126BF0->mode != 4 && D_80126BF0->mode != 5) {
                func_80027CEC();
            }
        case 1:
        case 2:
        case 3:
            D_80138210 = func_8002A88C();
            func_8003E078(D_80138210);
            break;
        case 4:
            if (arg != 0xB) {
                func_8000ECBC(arg, buf);
                func_8003E2C4(buf);
            } else {
                func_8000ED18(D_801380C0);
                func_8003E458(D_801380C0);
            }
            break;
        case 5:
        case 6:
        case 7:
            break;
        }
    }
}
