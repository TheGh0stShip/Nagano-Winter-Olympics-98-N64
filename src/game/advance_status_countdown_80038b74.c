extern unsigned char D_80137DF2;
extern signed char D_80137DF3;
extern unsigned char D_80138219;

void func_80038B74(void) {
    if (D_80137DF2 != 0) {
        D_80137DF3--;
        if (D_80137DF3 <= 0) {
            D_80137DF2 = 0;
        }
        if (D_80137DF3 == 0) {
            D_80138219 = 1;
        }
    }
}
