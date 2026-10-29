typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned char D_8036A000[];

void func_80001150(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xBA001402, 0x00300000);
    DISPLAY_COMMAND(D_80126BF4++, 0xFF000000 | ((*(unsigned short *)(D_80126BF0 + 0x7C8C6) & 3) << 19) | (320 - 1),
                    (unsigned int)&D_8036A000[*(short *)(D_80126BF0 + 0x7C8C0) * 0x25800] + 0x80000000);
    DISPLAY_COMMAND(D_80126BF4++, 0xF7000000, (((((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | (a & 1))) << 16) | (((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | (a & 1)));
    DISPLAY_COMMAND(D_80126BF4++, 0xF64FC3BC, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF7000000, 0x00010001);
    DISPLAY_COMMAND(D_80126BF4++, 0xF64FC01C, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF64FC4FC, 0x3A0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF601C39C, 0x20);
    DISPLAY_COMMAND(D_80126BF4++, 0xF64FC39C, 0x004E0020);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xBA001402, 0);
}
