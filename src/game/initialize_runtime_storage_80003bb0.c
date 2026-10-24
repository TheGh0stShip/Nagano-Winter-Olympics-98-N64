extern unsigned char D_8008F3F0[];
extern unsigned char *D_80126BF0;
extern void func_80003C10(void *storage, unsigned int size);
extern void func_8000C150(void);

void func_80003BB0(void) {
    func_80003C10(D_8008F3F0, 0x97800);
    D_80126BF0 = D_8008F3F0;
    *(unsigned short *)(D_80126BF0 + 0x7C8C6) = 2;
    func_8000C150();
}
