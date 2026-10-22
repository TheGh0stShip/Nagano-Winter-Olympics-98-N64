typedef struct Template {
    unsigned int words[0x1E];
} Template;

extern unsigned char *D_80126BF0;
extern Template D_80069068;

void func_80004B50(void) {
    *(Template *)(D_80126BF0 + 0x7FEE8) = D_80069068;
}
