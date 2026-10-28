extern unsigned char *D_80126BF0;
extern unsigned char D_801AA600[];
extern void func_80003870(unsigned char *dst, unsigned char *src, int size);
extern void func_8000C150(void);
extern void func_80007E5C(void);
extern void func_80006CBC(short level);
extern void func_8000611C(short level);
extern void func_80006BA8(short level);
extern void func_80006DC8(short level);
extern void func_80006F24(short level);

void func_80006FF4(short level) {
    func_80003870(D_80126BF0 + 0x977E0, D_801AA600, 0x3B800);
    func_8000C150();
    func_80007E5C();
    func_80006CBC(level);
    func_8000611C(level);
    func_80006BA8(level);
    func_80006DC8(level);
    func_80006F24(level);
}
