typedef struct Template {
    unsigned int words[0x1E];
} Template;

extern unsigned char *D_80126BF0;
extern unsigned char D_8006BAF0[];
extern Template D_8006E510;
extern unsigned short D_80137500[];

extern void func_80006EE0(unsigned short, unsigned char *);
extern void func_8002C5DC(unsigned short);

int func_8002C51C(unsigned short *values) {
    unsigned short i;

    func_80006EE0(0x32, D_8006BAF0);
    *(Template *)(D_80126BF0 + 0x7FBA0) = D_8006E510;
    for (i = 0; i < 6; i++) {
        func_8002C5DC(i);
        D_80137500[i] = values[i];
    }
    return 0;
}
