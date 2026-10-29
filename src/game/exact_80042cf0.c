typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned char D_0601F248[];
extern unsigned int D_8007249C;

void func_80042CF0(short index, unsigned char alpha) {
    *(DisplayCommand **)(D_80126BF0 + index * 0x138 + 0x84024) = D_80126BF4;
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, D_8007249C);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xFA000000, (alpha & 0xFF) | 0x2020FF00);
    DISPLAY_COMMAND(D_80126BF4++, 0x0400103F, (unsigned int)D_0601F248);
    DISPLAY_COMMAND(D_80126BF4++, 0xB1040200, 0x00020600);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xB9000002, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF9000000, 1);
    DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
}
