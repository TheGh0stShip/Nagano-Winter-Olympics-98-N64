typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct ImageSet {
    unsigned short enabled;
    unsigned short pad2;
    int unk4;
    void *images[4];
    int unk18;
    int unk1C;
    int unk20;
} ImageSet;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_8013356C;
extern ImageSet D_80133588;
typedef struct Palette {
    unsigned short colors[16];
} Palette;

extern Palette *D_8013359C;
extern int D_80133570;
extern DisplayCommand D_8006D320[];
extern void func_8000D218(ImageSet *set);

void func_8000D0EC(void) {
    Palette *image;

    if (D_80133588.enabled) {
        DISPLAY_COMMAND(D_8013356C++, 0x06000000, (unsigned int)D_8006D320);
        image = (Palette *)((char *)D_8013359C + D_80133570 * 32);
        DISPLAY_COMMAND(D_8013356C++, 0xFD100000, (unsigned int)image);
        DISPLAY_COMMAND(D_8013356C++, 0xE8000000, 0);
        DISPLAY_COMMAND(D_8013356C++, 0xF5000100, 0x07000000);
        DISPLAY_COMMAND(D_8013356C++, 0xE6000000, 0);
        DISPLAY_COMMAND(D_8013356C++, 0xF0000000, 0x0703C000);
        DISPLAY_COMMAND(D_8013356C++, 0xE7000000, 0);
        func_8000D218(&D_80133588);
        DISPLAY_COMMAND(D_8013356C++, 0xE7000000, 0);
    }
}
