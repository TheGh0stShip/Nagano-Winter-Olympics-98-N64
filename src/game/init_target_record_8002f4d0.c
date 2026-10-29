typedef struct Record2F4D0 {
    short active;
    short zero;
    unsigned char pad04[8];
    float x;
    float y;
    float z;
    float zero18;
    float w;
    float zero20;
    float a;
    float b;
    float c;
    unsigned char pad30[0xF8];
    int kind;
} Record2F4D0;

extern unsigned char *D_80126BF0;
extern float D_80137528[4];
extern unsigned char D_80137555;
extern float D_80071E10[];
extern unsigned char D_8006BA18[];
extern void func_80006EE0(int value, void *data);

void func_8002F4D0(void) {
    Record2F4D0 *record = (Record2F4D0 *)(D_80126BF0 + 0x88338);

    func_80006EE0(0x38, D_8006BA18);
    record->kind = 7;
    record->zero = 0;
    record->active = 1;
    record->x = D_80137528[0];
    record->y = D_80137528[1];
    record->z = D_80137528[2];
    record->zero18 = 0.0f;
    record->w = D_80137528[3];
    record->zero20 = 0.0f;
    record->a = (double)D_80071E10[D_80137555] * 0.1;
    record->b = (double)D_80071E10[D_80137555] * 0.1;
    record->c = (double)D_80071E10[D_80137555] * 0.1;
}
