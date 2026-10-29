typedef unsigned char u8;

typedef struct RuntimeState {
    u8 mode;
    u8 pad[0x57];
    u8 flag;
} RuntimeState;

extern void func_80021918(void);
extern void func_80021CA8(void);
extern void func_80021B4C(void);
extern void func_80021DD4(void);
extern void func_80021FFC(void);
extern void func_80022C28(void);
extern void func_80022A40(void);
extern void func_80022CF0(void);
extern void func_80022D10(void);

void func_80021840(RuntimeState *state) {
    state->flag = 0;
    switch (state->mode) {
    case 0: func_80021918(); break;
    case 1: func_80021CA8(); break;
    case 9:
    case 10: func_80021B4C(); break;
    case 2: func_80021DD4(); break;
    case 3: func_80021FFC(); break;
    case 4:
    case 8: func_80021FFC(); break;
    case 5: func_80022C28(); break;
    case 7: func_80022A40(); break;
    case 6: func_80022CF0(); break;
    case 11:
    case 12: func_80022D10(); break;
    }
}
