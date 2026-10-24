typedef struct CallbackPair {
    void *callback;
    void *argument;
} CallbackPair;

extern CallbackPair D_80194130[];
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_80059390(unsigned int index, void *callback, void *argument) {
    register unsigned int mask = func_8005BFD0();
    CallbackPair *pair = &D_80194130[index];

    pair->callback = callback;
    pair->argument = argument;
    func_8005BFF0(mask);
}
