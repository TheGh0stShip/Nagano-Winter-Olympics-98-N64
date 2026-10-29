typedef struct ContPad {
    unsigned short button;
    signed char stick_x;
    signed char stick_y;
    unsigned char errnum;
} ContPad;

typedef struct PortRecord {
    unsigned short connected;
    unsigned short button;
    unsigned short pressed;
    short stickX;
    short stickY;
    unsigned short dir;
    unsigned short dirPressed;
} PortRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80130BE0[];
extern ContPad D_80130C10[];
extern int func_8004E540(void *, void *, int);
extern void func_80050CA4(ContPad *);

void func_80005B34(void) {
    PortRecord *rec;
    unsigned short dir;
    short i;

    func_8004E540(D_80130BE0, 0, 1);
    func_80050CA4(D_80130C10);
    rec = (PortRecord *)(D_80126BF0 + 0x7C8F4);
    for (i = 0; i < 4; i++, rec++) {
        dir = D_80130C10[i].button;
        rec->pressed = (rec->button ^ dir) & dir;
        rec->button = dir;
        rec->stickX = D_80130C10[i].stick_x;
        rec->stickY = D_80130C10[i].stick_y;
        dir = 0;
        if (rec->stickX < -40) {
            dir = 0x200;
        }
        if (rec->stickX > 40) {
            dir |= 0x100;
        }
        if (rec->stickY > 40) {
            dir |= 0x800;
        }
        if (rec->stickY < -40) {
            dir |= 0x400;
        }
        rec->dirPressed = (rec->dir ^ dir) & dir;
        rec->dir = dir;
    }
}
