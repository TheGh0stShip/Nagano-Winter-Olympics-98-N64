typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

typedef struct Scene {
    unsigned char pad[0x12C];
    DisplayCommand *start;
} Scene;

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern DisplayCommand D_0601DB48[];

void func_8002F5D4(void) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x88338);

    scene->start = D_80126BF4;
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, (unsigned int)D_0601DB48);
    DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
}
