extern unsigned char *D_80126BF0;
extern unsigned char D_80071B44[];
extern unsigned short D_80071B54[];
extern void func_80048580(unsigned short);

void func_8002C414(void) {
    unsigned char index;

    index = D_80071B44[D_80126BF0[0x977EC]];
    func_80048580(D_80071B54[index]);
}
