typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern int D_8013355C;
extern DisplayCommand *D_8013356C;
extern int D_801330D0;
extern int D_80133558;
extern int D_80133560;
extern float D_80133564;
extern int D_80133568;
extern int D_80133570;
extern int D_80133578;
extern int D_8013357C;
extern int D_80133580;
extern unsigned char D_8006D2C8[];
extern void func_8000D0EC(void);
extern void func_8000CA30(unsigned char alpha);
extern void func_8000CAA0(void);
extern void func_8000D034(void *arg0);
extern void func_800485AC(int arg0);

DisplayCommand *func_8000C710(int arg0, DisplayCommand *gfx) {
    unsigned char alpha;

    D_8013355C = arg0;
    D_8013356C = gfx;
    DISPLAY_COMMAND(D_8013356C++, 0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C964));
    if (D_801330D0 == 0) {
        return D_8013356C;
    }
    switch (D_80133558) {
    case 0:
        alpha = *((unsigned char *)&D_8013357C + 3);
        if (alpha == 0) {
            D_80133558++;
        }
        func_8000D0EC();
        func_8000CA30(alpha);
        D_8013357C -= 0x10;
        if (D_8013357C < 0) {
            D_8013357C = 0;
        }
        return D_8013356C;
    case 1:
        if (D_80133564 >= 1.0) {
            D_80133560++;
            D_80133564 = 0.0f;
        }
        if (D_80133560 >= 23) {
            D_80133560 = 23;
            D_80133568 = 1;
            D_80133558++;
        }
        func_8000D0EC();
        func_8000CAA0();
        D_80133564 += 0.25;
        return D_8013356C;
    case 2:
        D_80133560 = 23;
        D_80133568 = 1;
        if (D_80133578 == 0) {
            func_800485AC(0x1D);
        }
        if (++D_80133578 >= 7) {
            func_8000D034(D_8006D2C8);
            D_80133578 = 0;
            D_80133558++;
        }
        func_8000D0EC();
        func_8000CAA0();
        return D_8013356C;
    case 3:
        if (D_80133580 < ++D_80133578) {
            D_8013357C = 0;
            D_80133558++;
        }
        if (D_80133570 != 31) {
            D_80133570++;
        }
        func_8000D0EC();
        return D_8013356C;
    case 4:
        alpha = *((unsigned char *)&D_8013357C + 3);
        if (alpha == 0xFF) {
            D_80133558++;
        }
        func_8000D0EC();
        func_8000CA30(alpha);
        D_8013357C += 0x10;
        if (D_8013357C >= 0x100) {
            D_8013357C = 0xFF;
        }
        return D_8013356C;
    case 5:
        func_800485AC(1);
        return D_8013356C;
    }
}
