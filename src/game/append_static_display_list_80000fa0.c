typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_80126BF4;
extern DisplayCommand D_8006C560[];

void func_80000FA0(void) {
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, (unsigned int)D_8006C560);
}
