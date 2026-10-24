extern unsigned char D_80138216;
extern unsigned char D_80138215;
extern unsigned char D_06002390[];
extern void func_80039004(void *index, float x, float y,
                          unsigned int type, void *resource,
                          unsigned int enabled);

unsigned char *func_8003EDF4(unsigned char *index) {
    func_80039004(index, -100.0f, -79.0f, 7, D_06002390, 1);
    D_80138216 = 0;
    D_80138215 = 1;
    index++;
    return index;
}
