typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

typedef struct Holder {
    unsigned char pad0[0x12C];
    DisplayCommand *list;
} Holder;

extern DisplayCommand *D_80126BF4;
extern unsigned char D_80071F80[];
extern unsigned char D_80072008[];
extern unsigned char D_80137566[];

void func_800304EC(Holder *holder) {
    int pad[9];
    DisplayCommand *last;

    holder->list = D_80126BF4;
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, (unsigned int)D_80071F80);
    DISPLAY_COMMAND(D_80126BF4++, 0xFD180000, (unsigned int)D_80137566);
    DISPLAY_COMMAND(D_80126BF4++, 0xF5180000, 0x07008020);
    DISPLAY_COMMAND(D_80126BF4++, 0xE6000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF3000000, 0x0700F400);
    DISPLAY_COMMAND(D_80126BF4++, 0xE7000000, 0);
    DISPLAY_COMMAND(D_80126BF4++, 0xF5180200, 0x8020);
    DISPLAY_COMMAND(D_80126BF4++, 0xF2000000, 0xC00C);
    DISPLAY_COMMAND(D_80126BF4++, 0x06000000, (unsigned int)D_80072008);
    last = D_80126BF4++;
    last->opcode = 0xB8000000;
    last->argument = 0;
}
