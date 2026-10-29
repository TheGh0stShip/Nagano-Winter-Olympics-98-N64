typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_80126BF4;
extern unsigned char D_003DA800[];

void func_80001408(void) {
    DISPLAY_COMMAND(D_80126BF4++, 0xFF10013F, (unsigned int)D_003DA800);
    DISPLAY_COMMAND(D_80126BF4++, 0xFE000000, (unsigned int)D_003DA800);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xBA001402, 0x00300000);
    DISPLAY_COMMAND(D_80126BF4++, 0xF7000000, 0xFFFCFFFC);
    DISPLAY_COMMAND(D_80126BF4++, 0xF64FC3BC, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
}
