typedef struct RuntimeCallbackState {
    unsigned char initialized;
    unsigned char padding[3];
    unsigned int value;
    void *data;
} RuntimeCallbackState;

extern RuntimeCallbackState D_8013CB08;
extern unsigned char D_8013CB18[];
extern void func_80047DAC(void);

void (*func_80047F28(RuntimeCallbackState **state))(void) {
    if (D_8013CB08.initialized == 0) {
        D_8013CB08.value = 0;
        D_8013CB08.data = D_8013CB18;
        D_8013CB08.initialized = 1;
    }

    *state = &D_8013CB08;
    return func_80047DAC;
}
