typedef struct Obj {
    char pad0[0x134];
    unsigned short unk134;
    char pad136[0x6];
    unsigned short unk13C;
    unsigned short unk13E;
    unsigned short unk140;
    unsigned short unk142;
    char pad144[0x8];
    short unk14C;
} Obj;
typedef struct Arg1 {
    char pad0[0x1C];
    unsigned short unk1C;
    char pad1E[0x6];
    short unk24;
} Arg1;
extern unsigned char D_80136C9D;
extern signed char D_80071A44[];
int func_80027978(Obj *);
signed char func_800279B8(short, Arg1 *, int);
void func_80027AE0(Obj *, signed char);
short func_80027C18(short);
void func_80048580(int);

void func_800265A0(Obj *arg0, Arg1 *arg1, unsigned int arg2) {
    short temp_s2;
    short var_v0;
    signed char var_s0;
    unsigned short temp_a1;

    temp_s2 = func_80027C18(arg1->unk24);
    var_s0 = arg0->unk140;
    if (D_80136C9D == 2) {
        var_s0 += 0x64;
    }
    temp_a1 = arg0->unk134;
    if (temp_a1 == 3) {
        var_s0 *= -1;
    }
    if ((arg0->unk13C == 2) || (arg0->unk13E == 3)) {
        var_v0 = arg0->unk140;
        if (D_80136C9D == 2) {
            var_v0 += 0x64;
        }
        if (temp_a1 == 3) {
            var_v0 *= -1;
        }
        switch (var_v0) {
        case 122:
            var_s0 = func_800279B8(temp_s2, arg1, 8);
            func_80027AE0(arg0, var_s0);
            break;
        case 111:
            var_s0 = func_800279B8(temp_s2, arg1, 0x12);
            func_80027AE0(arg0, var_s0);
            break;
        case 110:
            var_s0 = func_800279B8(temp_s2, arg1, 0x13);
            func_80027AE0(arg0, var_s0);
            break;
        case 112:
            var_s0 = func_800279B8(temp_s2, arg1, 0x14);
            func_80027AE0(arg0, var_s0);
            break;
        case 114:
            var_s0 = func_800279B8(temp_s2, arg1, 0x15);
            func_80027AE0(arg0, var_s0);
            break;
        case 113:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x16);
            func_80027AE0(arg0, var_s0);
            break;
        case 115:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x17);
            func_80027AE0(arg0, var_s0);
            break;
        case 117:
            var_s0 = func_800279B8(temp_s2, arg1, 0x18);
            func_80027AE0(arg0, var_s0);
            break;
        case 116:
            var_s0 = func_800279B8(temp_s2, arg1, 0x19);
            func_80027AE0(arg0, var_s0);
            break;
        case 118:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1A);
            func_80027AE0(arg0, var_s0);
            break;
        case 120:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1B);
            func_80027AE0(arg0, var_s0);
            break;
        case 119:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x1C);
            func_80027AE0(arg0, var_s0);
            break;
        case 121:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x1D);
            func_80027AE0(arg0, var_s0);
            break;
        case 123:
            var_s0 = func_800279B8(temp_s2, arg1, 0xE);
            func_80027AE0(arg0, var_s0);
            break;
        case 20:
            var_s0 = func_800279B8(temp_s2, arg1, 8);
            func_80027AE0(arg0, var_s0);
            break;
        case -22:
            var_s0 = func_800279B8(temp_s2, arg1, 0x12);
            func_80027AE0(arg0, var_s0);
            break;
        case -21:
            var_s0 = func_800279B8(temp_s2, arg1, 0x13);
            func_80027AE0(arg0, var_s0);
            break;
        case -26:
            var_s0 = func_800279B8(temp_s2, arg1, 0x14);
            func_80027AE0(arg0, var_s0);
            break;
        case -24:
            var_s0 = func_800279B8(temp_s2, arg1, 0x15);
            func_80027AE0(arg0, var_s0);
            break;
        case -23:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x16);
            func_80027AE0(arg0, var_s0);
            break;
        case -25:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x17);
            func_80027AE0(arg0, var_s0);
            break;
        case 22:
            var_s0 = func_800279B8(temp_s2, arg1, 0x18);
            func_80027AE0(arg0, var_s0);
            break;
        case 21:
            var_s0 = func_800279B8(temp_s2, arg1, 0x19);
            func_80027AE0(arg0, var_s0);
            break;
        case 26:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1A);
            func_80027AE0(arg0, var_s0);
            break;
        case 24:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1B);
            func_80027AE0(arg0, var_s0);
            break;
        case 23:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x1C);
            func_80027AE0(arg0, var_s0);
            break;
        case 25:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x1D);
            func_80027AE0(arg0, var_s0);
            break;
        case 31:
            var_s0 = func_800279B8(temp_s2, arg1, 0xE);
            func_80027AE0(arg0, var_s0);
            break;
        case 32:
            var_s0 = func_800279B8(temp_s2, arg1, 0xF);
            func_80027AE0(arg0, var_s0);
            break;
        case 33:
            var_s0 = func_800279B8(temp_s2, arg1, 0x10);
            func_80027AE0(arg0, var_s0);
            break;
        case 10:
            var_s0 = func_800279B8(temp_s2, arg1, 8);
            func_80027AE0(arg0, var_s0);
            break;
        case -14:
            var_s0 = func_800279B8(temp_s2, arg1, 0x11);
            func_80027AE0(arg0, var_s0);
            break;
        case -13:
            var_s0 = func_800279B8(temp_s2, arg1, 0x12);
            func_80027AE0(arg0, var_s0);
            break;
        case -18:
            var_s0 = func_800279B8(temp_s2, arg1, 0x13);
            func_80027AE0(arg0, var_s0);
            break;
        case -12:
            var_s0 = func_800279B8(temp_s2, arg1, 0x14);
            func_80027AE0(arg0, var_s0);
            break;
        case -11:
            var_s0 = func_800279B8(temp_s2, arg1, 0x15);
            func_80027AE0(arg0, var_s0);
            break;
        case -19:
            var_s0 = func_800279B8(temp_s2, arg1, 0x16);
            func_80027AE0(arg0, var_s0);
            break;
        case -16:
            var_s0 = func_800279B8(temp_s2, arg1, 0x17);
            func_80027AE0(arg0, var_s0);
            break;
        case -15:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x18);
            func_80027AE0(arg0, var_s0);
            break;
        case -17:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x19);
            func_80027AE0(arg0, var_s0);
            break;
        case 14:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1A);
            func_80027AE0(arg0, var_s0);
            break;
        case 13:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1B);
            func_80027AE0(arg0, var_s0);
            break;
        case 18:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1C);
            func_80027AE0(arg0, var_s0);
            break;
        case 12:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1D);
            func_80027AE0(arg0, var_s0);
            break;
        case 11:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1E);
            func_80027AE0(arg0, var_s0);
            break;
        case 19:
            var_s0 = func_800279B8(temp_s2, arg1, 0x1F);
            func_80027AE0(arg0, var_s0);
            break;
        case 16:
            var_s0 = func_800279B8(temp_s2, arg1, 0x20);
            func_80027AE0(arg0, var_s0);
            break;
        case 15:
            func_80048580(0x11C);
            var_s0 = func_800279B8(temp_s2, arg1, 0x21);
            func_80027AE0(arg0, var_s0);
            break;
        case 17:
            func_80048580(0x20E);
            var_s0 = func_800279B8(temp_s2, arg1, 0x22);
            func_80027AE0(arg0, var_s0);
            break;
        case 28:
            var_s0 = func_800279B8(temp_s2, arg1, 0xE);
            func_80027AE0(arg0, var_s0);
            break;
        case 29:
            var_s0 = func_800279B8(temp_s2, arg1, 0xF);
            func_80027AE0(arg0, var_s0);
            break;
        case 30:
            var_s0 = func_800279B8(temp_s2, arg1, 0x10);
            func_80027AE0(arg0, var_s0);
            break;
        case -35:
        case -27:
        case 126:
            var_s0 = func_800279B8(temp_s2, arg1, 9);
            func_80027AE0(arg0, var_s0);
            break;
        case 27:
        case 35:
            var_s0 = func_800279B8(temp_s2, arg1, 0xA);
            func_80027AE0(arg0, var_s0);
            break;
        case 1:
        case 101:
            var_s0 = func_800279B8(temp_s2, arg1, 0xB);
            func_80027AE0(arg0, var_s0);
            break;
        case 34:
        case 125:
            var_s0 = func_800279B8(temp_s2, arg1, 0xC);
            func_80027AE0(arg0, var_s0);
            break;
        case 0:
        case 100:
            var_s0 = func_800279B8(temp_s2, arg1, 0xD);
            func_80027AE0(arg0, var_s0);
            break;
        case 2:
        case 102:
            var_s0 = func_800279B8(temp_s2, arg1, 0x11);
            func_80027AE0(arg0, var_s0);
            break;
        default:
            var_s0 = func_800279B8(temp_s2, arg1, 8);
            func_80027AE0(arg0, var_s0);
            break;
        }
    }
    if ((arg2 >> 1) != 0) {
        switch (arg2) {
        case 0x2:
            if ((var_s0 != -0x24) && (var_s0 != -3)) {
                var_s0 = func_800279B8(temp_s2, arg1, 3);
            func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x4:
            if ((var_s0 != 0x24) && (var_s0 != 3)) {
                var_s0 = func_800279B8(temp_s2, arg1, 4);
            func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x8:
            if ((var_s0 != 0x25) && (var_s0 != 4)) {
                var_s0 = func_800279B8(temp_s2, arg1, 5);
            func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x10:
            if ((var_s0 != 0x27) && (var_s0 != 9)) {
                var_s0 = func_800279B8(temp_s2, arg1, 6);
            func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x20:
            if ((var_s0 != 0x26) && (var_s0 != 5)) {
                var_s0 = func_800279B8(temp_s2, arg1, 7);
            func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x40:
            if (func_80027978(arg0) != 0) {
                var_s0 = D_80071A44[D_80136C9D];
                func_80027AE0(arg0, var_s0);
            }
            break;
        case 0x80:
            if (func_80027978(arg0) != 0) {
                var_s0 = func_800279B8(temp_s2, arg1, 0);
            func_80027AE0(arg0, var_s0);
                if (arg1->unk1C != 0) {
                    arg0->unk134 = 3;
                }
            }
            break;
        case 0x100:
            if (func_80027978(arg0) != 0) {
                var_s0 = func_800279B8(temp_s2, arg1, 1);
            func_80027AE0(arg0, var_s0);
                if (arg1->unk1C != 0) {
                    arg0->unk134 = 3;
                }
            }
            break;
        case 0x200:
            if (func_80027978(arg0) != 0) {
                var_s0 = func_800279B8(temp_s2, arg1, 2);
            func_80027AE0(arg0, var_s0);
                if (arg1->unk1C != 0) {
                    arg0->unk134 = 3;
                }
            }
            break;
        case 0x800:
            switch (D_80136C9D) {
            case 2:
                if (var_s0 != 0x7E) var_s0 = func_800279B8(temp_s2, arg1, 9);
                break;
            case 1:
                if (var_s0 != -0x1B) var_s0 = func_800279B8(temp_s2, arg1, 9);
                break;
            default:
                if (var_s0 != -0x23) var_s0 = func_800279B8(temp_s2, arg1, 9);
                break;
            }
            func_80027AE0(arg0, var_s0);
            break;
        case 0x400:
            switch (D_80136C9D) {
            case 2:
                if (var_s0 != 0x7E) var_s0 = func_800279B8(temp_s2, arg1, 9);
                break;
            case 1:
                if (var_s0 != 0x1B) var_s0 = func_800279B8(temp_s2, arg1, 0xA);
                break;
            default:
                if (var_s0 != 0x23) var_s0 = func_800279B8(temp_s2, arg1, 0xA);
                break;
            }
            func_80027AE0(arg0, var_s0);
            break;
        case 0x1000:
            var_s0 = func_800279B8(temp_s2, arg1, 0xE);
            func_80027AE0(arg0, var_s0);
            break;
        case 0x2000:
            var_s0 = func_800279B8(temp_s2, arg1, 0x10);
            func_80027AE0(arg0, var_s0);
            break;
        default:
            var_s0 = func_800279B8(temp_s2, arg1, 0xB);
            func_80027AE0(arg0, var_s0);
            break;
        }
    }
    switch (D_80136C9D) {
    case 2:
        if ((var_s0 == 0x67 || var_s0 == 0x68 || var_s0 == 0x7C) && arg0->unk142 == 0x8C) {
            arg0->unk14C = 0x2710;
        }
        if ((var_s0 == 0x7E || var_s0 == 0x7E) && arg0->unk142 == 0x1D) {
            arg0->unk14C = 0x2710;
        }
        break;
    case 1:
        if ((var_s0 == 6 || var_s0 == 7 || var_s0 == 8) && arg0->unk142 == 0xEF) {
            arg0->unk14C = 0x2710;
        }
        if ((var_s0 == -0x1B || var_s0 == 0x1B) && arg0->unk142 == 0x14) {
            arg0->unk14C = 0x2710;
        }
        break;
    default:
        if ((var_s0 == 6 || var_s0 == 7 || var_s0 == 8) && arg0->unk142 == 0xEF) {
            arg0->unk14C = 0x2710;
        }
        if ((var_s0 == -0x23 || var_s0 == 0x23) && arg0->unk142 == 0x14) {
            arg0->unk14C = 0x2710;
        }
        break;
    }
}
