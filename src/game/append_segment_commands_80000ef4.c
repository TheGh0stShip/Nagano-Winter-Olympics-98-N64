typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned char D_8036A000[];
extern unsigned char D_003DA800[];

void func_80000EF4(void) {
    DISPLAY_COMMAND(D_80126BF4++, 0xBC000006, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xBC000406, (unsigned int)D_003DA800);
    DISPLAY_COMMAND(D_80126BF4++, 0xBC000806, (unsigned int)&D_8036A000[*(short *)(D_80126BF0 + 0x7C8C0) * 0x25800] + 0x80000000);
}
