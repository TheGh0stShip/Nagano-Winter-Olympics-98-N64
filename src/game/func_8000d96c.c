extern unsigned char *D_80126BF0;
extern int D_801335C0;
extern short D_801335C8;
extern int func_80007170(int arg0);
extern unsigned short func_80005C48(void);

int func_8000D96C(void) {
    switch (D_801335C0) {
    case 0:
        if (func_80007170(0x1F)) {
            D_801335C0 = 1;
            *(float *)(D_80126BF0 + 0x78000 + 0x78A8) = 64.0f;
            *(float *)(D_80126BF0 + 0x78000 + 0x78AC) = 72.0f;
            *(unsigned short *)(D_80126BF0 + 0x78000 + 0x789E) = 1;
        }
        break;
    case 1:
        if (D_801335C8++ >= 101) {
            return 1;
        }
        if (func_80005C48() & 0x9000) {
            if (D_801335C8 >= 11) {
                return -1;
            }
        }
        break;
    }
    return 0;
}
