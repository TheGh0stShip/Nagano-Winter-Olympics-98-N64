typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }
#define FILL_RECT(pkt, ulx, uly, lrx, lry) \
    DISPLAY_COMMAND(pkt, 0xF6000000 | (((lrx) & 0x3FF) << 14) | (((lry) & 0x3FF) << 2), \
                    (((ulx) & 0x3FF) << 14) | (((uly) & 0x3FF) << 2))

typedef struct Scheduler {
    unsigned char pad0[0xD48];
    unsigned long long unkD48;
    unsigned long long unkD50;
    unsigned long long unkD58;
} Scheduler;

extern unsigned long long func_8004F088(unsigned long long a, unsigned long long b);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);

void func_800045C0(Scheduler *sc, DisplayCommand **gfx, unsigned long long time) {
    int total;
    int cpu;
    int rsp;
    int rdp;
    int i;

    DISPLAY_COMMAND((*gfx)++, 0xE7000000, 0);
    DISPLAY_COMMAND((*gfx)++, 0xBA001402, 0);
    DISPLAY_COMMAND((*gfx)++, 0xFCFFFFFF, 0xFFFDF6FB);
    DISPLAY_COMMAND((*gfx)++, 0xB900031D, 0x0F0A4000);
    total = func_8004EF88(func_8004F088(time, 60), 16666);
    cpu = func_8004EF88(func_8004F088(sc->unkD48, 60), 16666);
    rsp = func_8004EF88(func_8004F088(sc->unkD50, 60), 16666);
    rdp = func_8004EF88(func_8004F088(sc->unkD58, 60), 16666);
    DISPLAY_COMMAND((*gfx)++, 0xFA000000, 0x00C800FF);
    FILL_RECT((*gfx)++, 25, 215, total + 25, 218);
    DISPLAY_COMMAND((*gfx)++, 0xFA000000, 0xC8C800FF);
    FILL_RECT((*gfx)++, 25, 219, cpu + 25, 222);
    DISPLAY_COMMAND((*gfx)++, 0xFA000000, 0xC80000FF);
    FILL_RECT((*gfx)++, cpu + 25, 219, rsp + 25, 222);
    DISPLAY_COMMAND((*gfx)++, 0xFA000000, 0x0000C8FF);
    FILL_RECT((*gfx)++, 25, 223, rdp + 25, 226);
    DISPLAY_COMMAND((*gfx)++, 0xFA000000, 0x00C8C8FF);
    for (i = 0; i < 5; i++) {
        FILL_RECT((*gfx)++, i * 60 + 25, 213, i * 60 + 26, 229);
    }
}
