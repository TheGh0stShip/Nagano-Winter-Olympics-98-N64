typedef struct Template {
    unsigned int words[0x1E];
} Template;

extern unsigned char *D_80126BF0;
extern Template D_8006E510;

void func_8000DCC0(void) {
    *(Template *)(D_80126BF0 + 0x7FBA0) = D_8006E510;
}
