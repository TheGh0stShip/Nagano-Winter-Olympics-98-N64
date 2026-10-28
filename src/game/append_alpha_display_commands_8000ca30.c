typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_8013356C;
extern DisplayCommand D_06008180[];

void func_8000CA30(unsigned char alpha) {
    if (alpha) {
        DISPLAY_COMMAND(D_8013356C++, 0xE7000000, 0);
        DISPLAY_COMMAND(D_8013356C++, 0xFA000000, alpha & 0xFF);
        DISPLAY_COMMAND(D_8013356C++, 0x06000000, (unsigned int)D_06008180);
    }
}
