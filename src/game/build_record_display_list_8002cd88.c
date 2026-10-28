typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Record {
    unsigned short state;
    unsigned char pad2[0x12A];
    DisplayCommand *start;
    unsigned char pad130[8];
} Record;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned int D_80071CA4[];

void func_8002CD88(unsigned short index, unsigned char kind) {
    Record *record = (Record *)(D_80126BF0 + 0x83EF8) + index;

    if (record->state == 1) {
        record->start = D_80126BF4;
        DISPLAY_COMMAND(D_80126BF4++, 0x06000000, D_80071CA4[kind]);
        DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
    }
}
