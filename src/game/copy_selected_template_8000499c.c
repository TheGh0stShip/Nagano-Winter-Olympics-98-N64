typedef struct Template {
    unsigned int words[0x1E];
} Template;

extern unsigned char *D_80126BF0;
extern unsigned short D_80069248;

void func_8000499C(void) {
    *(Template *)(D_80126BF0 + 0x7FBA0) =
        ((Template *)(D_80126BF0 + 0x7FB28))[D_80069248];
}
