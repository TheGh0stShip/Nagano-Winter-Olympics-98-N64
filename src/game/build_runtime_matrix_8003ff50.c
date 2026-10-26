extern unsigned char D_80130BE0[];
extern unsigned char D_80135790[];
extern int func_800532A0(void *matrix, void *record, int mode);

int func_8003FF50(unsigned char disabled) {
    int result = 0;

    if (disabled == 0) {
        result = func_800532A0(D_80130BE0, D_80135790, 0);
    }
    return result;
}
