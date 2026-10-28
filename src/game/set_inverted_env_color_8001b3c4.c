typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Fade {
    unsigned char pad0[6];
    unsigned short active;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Fade;

#define SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_80126BF4;

void func_8001B3C4(Fade *fade) {
    DISPLAY_COMMAND(D_80126BF4++, 0xFB000000, 0xFF);
    if (fade->active == 1) {
        DISPLAY_COMMAND(D_80126BF4++, 0xFB000000, SHIFTL(fade->a, 0, 8) | SHIFTL(255 - fade->r, 24, 8) | SHIFTL(255 - fade->g, 16, 8) | SHIFTL(255 - fade->b, 8, 8));
    }
}
