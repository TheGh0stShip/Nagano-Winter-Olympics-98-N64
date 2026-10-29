typedef struct Entry {
    float value;
    unsigned char pad[40];
} Entry;

extern unsigned char *D_80126BF0;
extern unsigned char D_80138219;
extern int D_80138210;
extern short D_8013821C;
extern float D_80137DEC;
extern short D_80137DF0;
extern unsigned char D_80137DE9;
extern unsigned char D_80137DEA;
extern unsigned char D_80137DF2;
extern unsigned char D_80137DF3;
extern Entry D_80137E04[];
extern float D_8008060C;
extern int func_8002A88C(void);
extern void func_8003E078(int);
extern int func_80038E0C(int);
extern short func_8002B4E4(void);
extern void func_80038BC8(void);

void func_80038C18(int arg) {
    int index;

    D_80138219 = arg;
    if (arg != 0) {
        D_80138210 = func_8002A88C();
        func_8003E078(D_80138210);
        if (D_80126BF0[0x977F1] == 21) {
            index = func_80038E0C(D_80126BF0[0x977EF]);
            if (index < 0 || index >= 16) {
                index = 15;
            }
            D_80137DEC = D_80137E04[index].value + D_8008060C;
            D_8013821C = func_8002B4E4();
            D_80137DF0 = 0x800;
            func_80038BC8();
        } else {
            index = func_80038E0C(D_80126BF0[0x977EF]);
            D_8013821C = index;
            D_80137DEC = D_80137E04[index].value;
            switch (D_80126BF0[0x977EC]) {
            case 4:
                D_80137DF0 = 0xA00;
                break;
            case 2:
            case 3:
            case 5:
                D_80137DF0 = 0x900;
                break;
            case 10:
                D_80137DF0 = 0x400;
                break;
            default:
                D_80137DF0 = 0x600;
                break;
            }
            func_80038BC8();
        }
    } else {
        D_80137DE9 = 0;
        D_80137DEA = 0;
        D_80137DF3 = 0;
        D_80137DF2 = 0;
    }
}
