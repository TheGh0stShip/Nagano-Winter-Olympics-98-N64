typedef unsigned short u16;

typedef struct Spinner {
    float x;
    float angle;
    float mode;
} Spinner;

typedef struct Record {
    unsigned char pad0[0xC];
    float x;
    unsigned char pad10[8];
    float angle;
    unsigned char pad1C[0x138 - 0x1C];
} Record;

typedef struct ColorRecord {
    unsigned char pad0[0x38];
    unsigned char color[0x100];
} ColorRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80134014;
extern short D_80134016;
extern int D_80134018;
extern Spinner D_80134020[6];
extern int func_80007170(int mode);
extern void func_8000FCA8(void);
extern void func_8000FD44(void);
extern void func_8000FCF4(void);
extern void func_800485AC(int id);
extern void func_80030EEC(int arg0, float arg1);
extern void func_80005CAC(void);
extern u16 func_80005C48(void);
extern unsigned short func_80005D74(void);
extern unsigned short func_80005D10(void);
extern void func_8002FC74(unsigned char *color, int r, int g, int b);
extern void func_8002FB28(unsigned char *color, int r, int g, int b, int step, int count, int delay);
void func_800104F8(short *selection);
void func_800106E4(short arg0);
void func_80010654(short index);

int func_8000FDB0(void) {
    if (func_80007170(0x1B) == 0) {
        return 0;
    }

    func_8000FCA8();
    func_8000FD44();
    func_8000FCF4();
    return 1;
}

int func_8000FDFC(void) {
    unsigned char i;
    int done = 0;
    Record *a;
    Record *b;

    D_80134020[0].x -= 10.0f;
    D_80134020[0].angle += 2.0f;
    for (i = 1; i < 6; i++) {
        if (D_80134020[i].x - D_80134020[i - 1].x > 100.0f) {
            D_80134020[i].x -= 10.0f;
            D_80134020[i].angle += 2.0f;
        }
        if (D_80134020[i].x < 0.0f) {
            if (D_80134020[i].mode == 0.0f) {
                D_80134020[i].mode = 1.0f;
            }
        }
        if (D_80134020[i].mode == 1.0f || D_80134020[i].mode == 2.0f) {
            D_80134020[i].angle += 10.0f;
            if (D_80134020[i].angle > 360.0f) {
                D_80134020[i].mode = -1.0f;
            }
        }
        if (D_80134020[i].angle > 360.0f) {
            D_80134020[i].angle -= 360.0f;
        }
        if (D_80134020[i].mode == -1.0f) {
            D_80134020[i].angle = 0.0f;
            if (i == 5) {
                done = 1;
            }
        }
    }
    a = &((Record *)(D_80126BF0 + 0x83EF8))[3];
    b = &((Record *)(D_80126BF0 + 0x83EF8))[8];
    for (i = 1; i < 6; i++, a++, b++) {
        if ((a->x = b->x = D_80134020[i].x) < 0.0f) {
            a->x = b->x = 0.0f;
        }
        if (i % 2 == 1) {
            a->x = b->x = -a->x;
        }
        a->angle = b->angle = D_80134020[i].angle;
    }
    if (done) {
        return 1;
    }
    return 0;
}

int func_80010048(void) {
    unsigned char i;
    unsigned char j;
    unsigned char done = 0;
    Record *a;
    Record *b;
    short sel = D_80134016 + 1;

    if (D_80134020[sel].mode == 0.0f) {
        D_80134020[sel].angle += 20.0f;
        if (D_80134020[sel].angle > 360.0f) {
            D_80134020[sel].angle = 0.0f;
            D_80134020[sel].mode = 1.0f;
            if (!(D_80134014 & 0x8000)) {
                if (D_80134016 != 4) {
                    func_800485AC(8);
                } else {
                    func_800485AC(0xD);
                }
                func_80030EEC(1, 3.0f);
            }
        }
    }
    for (i = sel - 1, j = 0; i > 0; i--, j++) {
        if (D_80134020[i].mode == 2.0f) {
            continue;
        }
        if (D_80134020[i + 1].mode == 0.0f) {
            continue;
        }
        D_80134020[i].angle += (8 - j) * 2;
        if (D_80134020[i].angle > 360.0f) {
            D_80134020[i].angle = 0.0f;
            D_80134020[i].mode = 2.0f;
        }
        if (D_80134020[i].angle > 90.0f) {
            D_80134020[i].mode = 1.0f;
        }
    }
    for (i = sel + 1, j = 0; i < 6; i++, j++) {
        if (D_80134020[i].mode == 2.0f) {
            continue;
        }
        if (D_80134020[i - 1].mode == 0.0f) {
            continue;
        }
        D_80134020[i].angle += (8 - j) * 2;
        if (D_80134020[i].angle > 360.0f) {
            D_80134020[i].angle = 0.0f;
            D_80134020[i].mode = 2.0f;
        }
        if (D_80134020[i].angle > 90.0f) {
            D_80134020[i].mode = 2.0f;
        }
    }
    for (i = 1; i < 7; i++) {
        if (sel == i) {
            continue;
        }
        if (D_80134020[i].mode == 1.0f || D_80134020[i].mode == 2.0f) {
            D_80134020[i].x -= 10.0f;
            D_80134020[i].angle += 2.0f;
        }
    }
    for (i = 1; i < 7; i++) {
        if (sel == i) {
            continue;
        }
        if (D_80134020[i].x > 0.0f) {
            break;
        }
        if (i == 6) {
            done = 1;
        }
    }
    a = &((Record *)(D_80126BF0 + 0x83EF8))[3];
    b = &((Record *)(D_80126BF0 + 0x83EF8))[8];
    for (i = 1; i < 6; i++, a++, b++) {
        if ((a->x = b->x = 300.0f - D_80134020[i].x) < 0.0f) {
            a->x = b->x = 0.0f;
        }
        if (i % 2 == 0) {
            a->x = b->x = -b->x;
        }
        a->angle = b->angle = D_80134020[i].angle;
    }
    if (done) {
        return 1;
    }
    return 0;
}

int func_8001049C(void) {
    switch (D_80134016) {
        case 0:
            return 20;
        case 1:
            return 21;
        case 2:
            return 22;
        case 3:
            return 24;
        default:
            return 23;
    }
}

void func_800104F8(short *selection) {
    short unused;
    unsigned short first;
    unsigned short second;

    func_80005CAC();
    first = func_80005C48();
    second = func_80005D74();
    func_80005D10();
    if ((first & 0x400) || (second & 0x400)) {
        (*selection)++;
        if (*selection >= 5) {
            *selection -= 5;
        }
    }
    if ((first & 0x800) || (second & 0x800)) {
        (*selection)--;
        if (*selection < 0) {
            *selection += 5;
        }
    }
}

int func_800105A4(void) {
    u16 buttons[1];
    long long unused;
    int oldValue;

    func_80005CAC();
    buttons[0] = func_80005C48();
    oldValue = D_80134016;
    func_800104F8(&D_80134016);
    if (oldValue != D_80134016) {
        func_800485AC(0x46A);
        func_800106E4(oldValue);
    }
    if (buttons[0] & 0x9000) {
        func_800485AC(0x468);
        func_8000FCF4();
        return 1;
    }
    D_80134018++;
    func_80010654(D_80134016);
    return 0;
}

void func_80010654(short index) {
    int unused[5];
    ColorRecord *record = &((ColorRecord *)(D_80126BF0 + 0x842A0))[index];
    unsigned char *color = record->color;

    func_8002FC74(color, 0x80, 0x80, 0x80);
    func_8002FB28(color, 0xD0, 0xD0, 0xD0, -16, 5, 16);
}

void func_800106E4(short arg0) {
    unsigned short i;
    ColorRecord *record;
    unsigned char *color;

    record = &((ColorRecord *)(D_80126BF0 + 0x83EF8))[3];
    for (i = 3; i < 8; i++, record++) {
        color = record->color;
        func_8002FC74(color, 0x80, 0x80, 0x80);
        func_8002FB28(color, 0, 0, 0, -16, 5, 16);
    }
    record = &((ColorRecord *)(D_80126BF0 + 0x83EF8))[8];
    for (i = 8; i < 13; i++, record++) {
        color = record->color;
        func_8002FC74(color, 0x80, 0x80, 0x80);
        func_8002FB28(color, 0xD0, 0xD0, 0xD0, -16, 5, 16);
    }
}
