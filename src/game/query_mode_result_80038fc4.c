extern unsigned char D_80063990[];
extern int func_80005F78(int, void *);

int func_80038FC4(void) {
    struct {
        int result;
        int pad;
    } local;

    local.result = 3;

    if (func_80005F78(20, D_80063990) == 0) {
        local.result = 1;
    }
    return local.result;
}
