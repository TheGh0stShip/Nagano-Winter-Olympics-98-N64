typedef struct DisplayCommand { unsigned int opcode; unsigned int argument; } DisplayCommand;
extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern void func_80018F20(unsigned char id, int alpha, float y, float x, float z);
void func_80034958(float x) {
    unsigned short i = 1;
    *(DisplayCommand **)(D_80126BF0 + 0x886D4) = D_80126BF4;
    *(unsigned short *)(D_80126BF0 + 0x885A8) = i;
    *(unsigned short *)(D_80126BF0 + 0x885AA) = i;
    func_80018F20(i, 255, 160.0f, x, -10.0f);
    { DisplayCommand *_g = D_80126BF4++; _g->opcode = 0xB8000000; _g->argument = 0; }
}
