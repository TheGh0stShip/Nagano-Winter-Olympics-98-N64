typedef struct Record {
    short flag;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[8];
} Record;

typedef struct State {
    unsigned char pad[0x1C];
    short index;
} State;

extern unsigned char *D_80126BF0;
extern State D_80131920;
extern void func_8000A8EC(int value);

void func_8000B924(void) {
    func_8000A8EC(0);
    ((Record *)(D_80126BF0 + 0x83EF8))[D_80131920.index].value = 0;
    ((Record *)(D_80126BF0 + 0x83EF8))[D_80131920.index].flag = 0;
}
