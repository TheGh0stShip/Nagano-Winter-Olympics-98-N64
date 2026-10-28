typedef struct Channel {
    int active;
    unsigned char pad[0xCC];
} Channel;

extern unsigned char D_80179670;
extern Channel *D_80179924;
extern Channel D_8018C980[];
extern void func_8004A250(unsigned char index);

void func_8004A144(void) {
    int i;

    if (D_80179670) {
        D_80179670 = 0;
        for (i = 0; i < 16; i++) {
            D_80179924 = &D_8018C980[i];
            if (D_80179924->active) {
                func_8004A250(i);
            }
        }
    }
}
