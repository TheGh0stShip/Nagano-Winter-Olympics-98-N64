typedef struct {
    unsigned char pad[0x977EC];
    unsigned char mode;
    unsigned char padED;
    unsigned char flagEE;
    unsigned char cur;
    unsigned char count;
    unsigned char type;
} Game;

extern int func_80007170(int);
extern void func_8000F360(char *);
extern int func_80011540(int);
extern void func_80032040(void);
extern int func_80032074(int);
extern void func_80048580(int);
extern void func_801954A0(void);
extern void func_80195554(void);
extern void func_801955CC(void);
extern int func_801956F4(void);
extern int func_8019583C(void);
extern void func_801958E0(void);
extern int func_80195C74(void);
extern unsigned char D_8006E590;
typedef struct { char *p[4]; } NameTbl;
extern NameTbl D_8006E594;
extern Game *D_80126BF0;
extern unsigned short D_80134084;
extern unsigned short D_80134086;
extern unsigned char D_801376D0[];
extern unsigned char D_801376D8[][9];
extern int D_801386A4;

signed char func_80010A20(void) {
    signed char ret;
    int found;
    NameTbl names;
    char buf[0xC4];
    short i;

    ret = 0;
    switch (D_80134084) {
    case 1000:
        if (func_80007170(0xE) != 0) {
            D_80134084 = 0;
        }
        break;
    case 0:
        if (D_80134086 == 0) {
            func_80011540(2);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            if (D_80126BF0->type == 0x14) {
                func_801954A0();
                D_80134084 = 1;
            } else {
                func_801958E0();
                D_80134084 = 1;
            }
            D_80134086 = 0;
        }
        break;
    case 1:
        found = func_80195C74();
        ret = found;
        if (found == 1) {
            D_80134084 = 0x64;
            ret = 0;
        } else if (found == 2) {
            D_80134084 = 0x19;
            ret = 0;
        } else if (found == 3) {
            D_80134084 = 0x28;
            func_80032040();
            ret = 0;
        }
        break;
    case 0x64:
        if (D_80134086 == 0) {
            func_80011540(3);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801954A0();
            D_80134084 = 0xA;
            D_80134086 = 0;
        }
        break;
    case 0xA:
        found = func_8019583C();
        ret = found;
        if (found == 1) {
            D_80134084 = 0x6E;
            ret = 0;
        } else if (found == 2) {
            D_80134084 = 0x1A;
            ret = 0;
        } else if (found == -1) {
            D_80134084 = 0x78;
            ret = 0;
        }
        break;
    case 0x6E:
        if (D_80134086 == 0) {
            func_80011540(4);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801954A0();
            D_80134084 = 0x14;
            D_80134086 = 0;
        }
        break;
    case 0x78:
        if (D_80134086 == 0) {
            func_80011540(2);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801955CC();
            D_80134084 = 1;
            D_80134086 = 0;
        }
        break;
    case 0x14:
        found = func_801956F4();
        ret = found;
        if (found == -1) {
            D_80134084 = 0x8C;
            ret = 0;
        } else if (found == 1) {
            if (D_80126BF0->cur < D_80126BF0->count - 1) {
                found = 0;
                for (i = D_80126BF0->cur + 1; i < D_80126BF0->count; i++) {
                    if (!((D_8006E590 >> i) & 1)) {
                        D_80126BF0->cur = i;
                        found = 1;
                        D_80134084 = 0x82;
                        ret = 0;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            ret = 0;
            func_80032040();
            D_80134084 = 0x1E;
        }
        break;
    case 0x82:
        if (D_80134086 == 0) {
            func_80011540(2);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801955CC();
            D_80134084 = 1;
            D_80134086 = 0;
        }
        break;
    case 0x8C:
        if (D_80134086 == 0) {
            func_80011540(3);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_80195554();
            D_80134084 = 0xA;
            D_80134086 = 0;
        }
        break;
    case 0x19:
        if (D_801376D8[D_80126BF0->cur][0] == 0) {
            D_801376D0[D_80126BF0->cur] = 0;
        }
    case 0x1A:
        if (D_801376D8[D_80126BF0->cur][0] == 0) {
            names = D_8006E594;
            i = 0;
            while ((D_801376D8[D_80126BF0->cur][i] = names.p[D_80126BF0->cur][i]) != 0) {
                i++;
            }
            for (; i < 9; i++) {
                D_801376D8[D_80126BF0->cur][i] = 0;
            }
        }
        if (D_80126BF0->cur < D_80126BF0->count - 1) {
            found = 0;
            for (i = D_80126BF0->cur + 1; i < D_80126BF0->count; i++) {
                if (!((D_8006E590 >> i) & 1)) {
                    D_80126BF0->cur = i;
                    D_80134084 = 0x82;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        func_80032040();
        D_80134084 = 0x1E;
        break;
    case 0x1D:
        if (func_80007170(0xE) != 0) {
            func_80032040();
            D_80134084 = 0x1E;
        }
        break;
    case 0x1E:
        found = func_80032074(0);
        ret = found;
        if (found != 0) {
            for (i = 0; i < D_80126BF0->count; i++) {
                if (!((D_8006E590 >> i) & 1)) {
                    ret = 0;
                    break;
                }
            }
            if (ret == 0) {
                D_80126BF0->cur = i;
                D_80134084 = 0x82;
            } else {
                for (i = 0; i < 4; i++) {
                    D_8006E590 &= (1 << i) ^ 0xFF;
                }
                D_80126BF0->cur = 0;
                if (D_80126BF0->type == 0x15) {
                    D_80126BF0->flagEE = 0;
                } else if (D_80126BF0->mode == 0xB && D_801386A4 == 0) {
                    buf[0] = 0;
                    func_8000F360(buf);
                }
            }
        }
        break;
    case 0x28:
        found = func_80032074(1);
        ret = found;
        if (found != 0) {
            if (found == -1) {
                D_80134084 = 0x96;
                D_80134086 = 0;
                ret = 0;
            } else if (found == -2) {
                if (D_80126BF0->type == 0x14) {
                    D_80134084 = 0x9B;
                    D_80134086 = 0;
                    ret = 0;
                } else {
                    func_80048580(7);
                }
            } else {
                D_80126BF0->cur = 0;
                for (i = 0; i < 4; i++) {
                    D_8006E590 &= (1 << i) ^ 0xFF;
                }
            }
        }
        break;
    case 0x96:
        if (D_80134086 == 0) {
            func_80011540(2);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801958E0();
            D_80134084 = 1;
            D_80134086 = 0;
        }
        break;
    case 0x9B:
        if (D_80134086 == 0) {
            func_80011540(2);
            D_80134086++;
        } else if (D_80134086 == 1) {
            if (func_80011540(0) != 0) {
                D_80134086++;
            }
        } else {
            func_801954A0();
            D_80134084 = 1;
            D_80134086 = 0;
        }
        break;
    default:
        D_80134084 = 0;
        break;
    }
    return ret;
}
