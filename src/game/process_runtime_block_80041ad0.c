typedef struct RuntimeBlock {
    unsigned char first;
    unsigned char payload[0xDB];
    unsigned char second[0x648];
    unsigned char third[0x9A];
    unsigned char flag;
    unsigned char result;
    unsigned char pad7C0[0xC];
} RuntimeBlock;

extern RuntimeBlock *D_800730A8;
extern unsigned char D_8006D450;
extern void func_80041B80(unsigned char *);
extern void func_80041F08(unsigned char *);
extern void func_80041D10(unsigned char *);
extern void func_80011CE4(unsigned char *);

void func_80041AD0(unsigned char index) {
    unsigned char flag;

    func_80041B80(&D_800730A8[index].payload[0]);
    func_80041F08(&D_800730A8[index].second[0]);
    func_80041D10(&D_800730A8[index].third[0]);
    flag = D_800730A8[index].flag;
    func_80011CE4(&flag);
    D_8006D450 = D_800730A8[index].result;
}
