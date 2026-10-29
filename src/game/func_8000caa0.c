typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

typedef struct MatrixSet {
    unsigned char data[0x180];
} MatrixSet;

extern DisplayCommand *D_8013356C;
extern int D_8013355C;
extern int D_80133560;
extern float D_80133564;
extern MatrixSet D_801330D8[];
extern unsigned char D_8006D020[];
extern unsigned char D_8006CAE0[];
extern unsigned char D_8006C840[];
extern unsigned char D_8006CD80[];
extern DisplayCommand D_060080E0[];
extern DisplayCommand D_06008208[];
extern DisplayCommand D_06008B98[];
extern DisplayCommand D_06009528[];
extern void func_8000CD60(void *mtx, void *frames, int index, float t);
extern void func_8000CBCC(void *displayList, void *mtx, void *frames, int index, float t);

void func_8000CAA0(void) {
    unsigned char *mtx = D_801330D8[D_8013355C].data;

    func_8000CD60(mtx, D_8006D020, D_80133560, D_80133564);
    DISPLAY_COMMAND(D_8013356C++, 0x06000000, (unsigned int)D_060080E0);
    func_8000CBCC(D_06008208, mtx + 0xC0, D_8006CAE0, D_80133560, D_80133564);
    func_8000CBCC(D_06008B98, mtx + 0x100, D_8006C840, D_80133560, D_80133564);
    func_8000CBCC(D_06009528, mtx + 0x140, D_8006CD80, D_80133560, D_80133564);
    DISPLAY_COMMAND(D_8013356C++, 0xE7000000, 0);
}
