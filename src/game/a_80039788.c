extern unsigned char D_80072AF8;
extern unsigned char D_80138214;
extern unsigned char D_80138217;
extern unsigned char D_801380B8;
extern float D_801381F8;
extern unsigned char *D_80126BF0;
extern unsigned char D_80063948[];
extern unsigned char D_80063958[];
extern unsigned char D_800636E0[];
extern unsigned char D_80063990[];

extern void func_8003ED24(int);
extern void func_80038B74(void);
extern void func_80039750(int, void *);
extern void func_80007F90(int, void *);
extern int func_8003C0F0(void);
extern int func_8003C780(void);
extern int func_8003E904(void);
extern void func_8003B29C(int, int);
extern int func_80039B24(void);
extern void func_80039D54(void);
extern int func_8003D06C(void);
extern void func_80039D94(void);
extern void func_8003A378(void);
extern void func_8003955C(void);
extern void func_8003969C(void);

int func_80039788(void) {
    int result = 0;

    if (D_80072AF8 == 0) {
        return 0;
    }
    func_8003ED24(0x18);
    func_80038B74();
    switch (D_80138214) {
    case 4:
    case 5:
        func_80039750(1, D_80063948);
        func_80039750(7, D_80063958);
        func_80039750(10, D_800636E0);
        func_80007F90(0x14, D_80063990);
        break;
    }
    switch (D_80138214) {
    case 2:
    case 7:
        return func_8003C0F0();
    case 4:
    case 5:
    case 6:
        return func_8003C780();
    case 3:
        return func_8003E904();
    default:
        func_8003B29C(0x19, 1);
        if (D_80138214 == 0) {
            return 1;
        }
        switch (D_801380B8) {
        case 0:
            D_801381F8 = D_801381F8 + 0.047123891676382035;
            if (func_80039B24() == 0) {
                D_801380B8 = 1;
            }
            func_80039D54();
            break;
        case 1:
            if (D_80138217 == 1) {
                D_801381F8 = 3.769f;
                D_801380B8 = 5;
            }
            break;
        case 5:
            if (D_80126BF0[0x977F1] == 0x15) {
                if (D_801381F8 >= 1.5707963267948966) {
                    D_801381F8 = 1.5707964f;
                }
            }
            if (func_8003D06C()) {
                result = 1;
            }
            func_80039D94();
            func_8003A378();
            break;
        case 6:
            break;
        }
        func_8003B29C(0x19, 0);
        func_8003955C();
        if (result == 1) {
            func_8003969C();
        }
        return result;
    }
}
