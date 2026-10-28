typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_80126BF4;
extern unsigned int D_8006F100[];

void func_8001805C(int arg0, int arg1, unsigned short index) {
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, D_8006F100[index]);
}
