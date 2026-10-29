typedef struct TextRecord {
    unsigned short state;
    unsigned char pad2[0xA];
    float x;
    float y;
    float z;
    unsigned char pad18[0x148 - 0x18];
} TextRecord;

extern unsigned char *D_80126BF0;
extern void func_80019148(TextRecord *record, unsigned char kind, unsigned short type, float x, float y, float z);
extern void func_80018704(TextRecord *record, char *text, int unused, float x, float y, float z);

void func_8000DAC0(void) {
    TextRecord *record = (TextRecord *)(D_80126BF0 + 0x91FA8);

    record->state = 1;
    record->x = 0.0f;
    record->y = 0.0f;
    record->z = 0.0f;
    func_80019148(record++, 0, 0xBF, 0.0f, -100.0f, 0.0f);
    record->state = 1;
    record->z = 0.0f;
    record->y = 0.0f;
    record->x = 0.0f;
    func_80018704(record, "No Controller", 0, -60.0f, -102.0f, 30.0f);
}
