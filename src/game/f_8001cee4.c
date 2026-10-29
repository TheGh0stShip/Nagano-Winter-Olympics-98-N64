typedef struct Template {
    unsigned int words[0x1E];
} Template;

typedef struct ViewRecord {
    unsigned short active;
    unsigned char pad2[0x26];
    float value28;
    unsigned char pad2C[0x28];
    float value54;
    unsigned char pad58[0x20];
} ViewRecord;

extern unsigned char *D_80126BF0;
extern Template D_8006E510;
extern int D_8006F7C4;
extern int D_80136704;
extern unsigned char D_801366F8;
extern void func_8001E020(int index, int value);
extern void func_8001DF00(int index, int state);
extern void func_8001DE10(int width, int height);
extern void func_8001E0C0(void);
extern void func_8001E198(void);

int func_8001CEE4(void) {
    D_80136704 = 0;
    *(Template *)(D_80126BF0 + 0x7FB28) = D_8006E510;
    *(Template *)(D_80126BF0 + 0x7FBA0) = D_8006E510;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))[0].value54 = 0.0f;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))[1].active = 1;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))[D_8006F7C4].active = 1;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))[D_8006F7C4].value28 = 0;
    func_8001E020(0, 0);
    func_8001DF00(0, 0);
    func_8001DF00(1, 0);
    func_8001DF00(2, 0);
    func_8001DF00(3, 0);
    func_8001DF00(4, 0);
    func_8001DF00(5, 0);
    func_8001DE10(320, 240);
    func_8001E0C0();
    func_8001E198();
    D_801366F8 = 0;
    return 1;
}
