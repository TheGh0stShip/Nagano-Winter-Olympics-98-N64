typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Scene {
    unsigned char pad[0x12C];
    DisplayCommand *start;
} Scene;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_80126BF4;
extern DisplayCommand D_80071F80[];
extern unsigned char D_80071F34;
extern signed char D_80071F3C;

void func_80030634(Scene *scene) {
    short level;

    scene->start = D_80126BF4;
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, (unsigned int)D_80071F80);
    level = D_80071F34;
    level -= D_80071F3C;
    if (level < 0) {
        level = 0;
    }
    D_80071F34 = level;
    DISPLAY_COMMAND(D_80126BF4++, 0xF9000000, D_80071F34 & 0xFF);
    DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
}
