typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Scene {
    unsigned short active;
    unsigned char pad2[0x12A];
    DisplayCommand *start;
} Scene;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned int D_80071CBC[];

void func_8002D508(void) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x88338);

    if (scene->active == 1) {
        scene->start = D_80126BF4;
        DISPLAY_COMMAND(D_80126BF4++, 0x06000000, D_80071CBC[D_80126BF0[0x977EC]]);
        DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
        DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
    }
}
