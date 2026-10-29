extern int func_8002E694(void);
extern void func_8002E6C8(void);
extern unsigned char func_8002E700(void);
extern void func_8002E728(void);
extern void func_8002E7C0(void);
extern int func_8002E804(int);
extern void func_8002E894(void);
extern void func_8002E8C4(int);
extern void func_8002E90C(void);
extern void func_8002E94C(int);
extern int func_8002E9DC(void);
extern void func_8002EA08(void *);
extern void func_8002EA98(unsigned char);
extern void func_8002EB3C(unsigned char);
extern void func_8002EC10(void);
extern void func_8002EC64(int, int);
extern void func_8002EDE8(int);
extern int func_8002EF28(float);
extern int func_8002F014(float);
extern void func_8002F1C0(void);
extern void func_8002F2B4(unsigned char);
extern void func_8002F4D0(void);
extern void func_8002F5D4(void);
extern void func_8002F634(void);
extern void func_80030DE8(void);
extern void func_80030E30(void);
extern void func_8003E904(void);
typedef struct { char pad[0x977EC]; unsigned char course; } Big;
extern Big *D_80126BF0;
extern unsigned char D_80137520;
extern unsigned char D_80137550[];
extern unsigned char D_80137555;
extern unsigned short D_80137556;
extern unsigned char D_8013755C;
extern unsigned char D_8013755D;
extern unsigned char D_8013755E;
extern unsigned char D_80071E48[];

signed char func_8002D998(void) {
    unsigned char i;
    unsigned char pz[3];
    unsigned char flagA;
    unsigned char padf;
    unsigned char flagB;

    switch (D_80137520) {
    case 0:
        D_8013755E = 0;
        func_8002EC10();
        D_80137555 = D_80126BF0->course;
        D_8013755D = func_8002E700();
        func_8002EA08(D_80137550);
        if (func_8002E9DC() != 0) {
            D_80137520++;
        }
        return 0;
    case 1:
        D_80137556 = 0;
        func_8002E7C0();
        for (i = 0; i < D_8013755D; i++) {
                func_8002F2B4(i);
                func_8002EB3C(i);
        }
        func_8002E6C8();
        func_8002EDE8(0);
        func_8002EC64(2, 1);
        func_8002F1C0();
        func_8002F4D0();
        func_8002F5D4();
        func_8002E94C(3);
        D_80137520++;
        break;
    case 2:
        D_8013755E++;
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (D_8013755E >= 0x15) {
            func_8002E90C();
            func_80030DE8();
            D_80137520++;
        }
        break;
    case 3:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if ((func_8002EF28(0.03f) == 1) && (D_80137520 == 3)) {
            func_8002E8C4(2);
            D_80137520++;
        }
        break;
    case 4:
        func_8002E728();
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002E804(0) != 0) {
            D_80137520++;
        }
        break;
    case 5:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        func_8002EDE8(1);
        func_8002EC64(2, 1);
        func_8002F1C0();
        D_80137520++;
        break;
    case 6:
        func_8002E728();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (func_8002E804(1) != 0) {
            D_80137520++;
        }
        break;
    case 7:
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002EDE8(2);
        func_8002EC64(2, 1);
        func_8002F1C0();
        D_80137520++;
        break;
    case 8:
        func_8002E728();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (func_8002E804(2) != 0) {
            D_80137520++;
        }
        break;
    case 9:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002EB3C(1);
        func_8002F5D4();
        func_8002EDE8(0);
        func_8002EC64(1, 1);
        func_8002F1C0();
        func_8002E94C(2);
        func_8002E8C4(1);
        D_80137520++;
        break;
    case 10:
        func_8002E728();
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002E804(0) != 0) {
            D_80137520++;
        }
        break;
    case 11:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        func_8002EDE8(1);
        func_8002EC64(1, 1);
        func_8002F1C0();
        D_80137520++;
        break;
    case 12:
        func_8002E728();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (func_8002E804(1) != 0) {
            D_80137520++;
        }
        break;
    case 13:
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002EDE8(2);
        func_8002EC64(1, 1);
        func_8002F1C0();
        D_80137520++;
        break;
    case 14:
        func_8002E728();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (func_8002E804(2) != 0) {
            D_80137520++;
        }
        break;
    case 15:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002EB3C(0);
        func_8002F5D4();
        func_8002EDE8(0);
        func_8002EC64(0, 1);
        func_8002F1C0();
        func_8002E94C(1);
        func_8002E8C4(0);
        D_80137520++;
        break;
    case 16:
        func_8002E728();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        if (func_8002E804(0) != 0) {
            D_80137520++;
        }
        break;
    case 17:
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F5D4();
        func_8002EDE8(1);
        func_8002EC64(0, 1);
        func_8002F1C0();
        D_80137520++;
        break;
    case 18:
        func_8002E728();
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002E804(1) != 0) {
            if (D_80071E48[D_80137555] != 0) {
                D_80137520 = 0x16;
            } else {
                D_80137520 = 0x13;
            }
        }
        break;
    case 19:
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EB3C(i);
                func_8002EA98(i);
        }
        func_8002EDE8(2);
        func_8002EC64(0, 0);
        func_8002F1C0();
        func_8002E94C(4);
        D_80137520++;
        break;
    case 20:
        D_80137556 += 1;
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002F014(0.8f) != 0) {
            D_80137520 = 0x15;
            func_8002E894();
            func_80030E30();
        }
        break;
    case 21:
        flagA = 0;
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        func_8002F014(0.8f);
        func_8002E94C(5);
        func_8002E94C(5);
        if (func_8002E694() != 0) {
            flagA = 1;
        }
        if (flagA == 1) {
            D_80137520 = 0x1B;
        }
        break;
    case 22:
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EB3C(i);
                func_8002EA98(i);
        }
        func_8002EDE8(2);
        func_8002EC64(0, 0xF4);
        func_8002F1C0();
        func_8002E94C(4);
        D_80137520++;
        break;
    case 23:
        D_80137556 += 1;
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002EF28(0.01f) != 0) {
            D_80137520 = 0x18;
        }
        break;
    case 24:
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        D_80137520 = 0x19;
        func_8002E894();
        break;
    case 25:
        func_80030E30();
        D_80137520 = 0x1A;
        /* fallthrough */
    case 26:
        flagB = 0;
        func_8002F5D4();
        for (i = 0; i < D_8013755D; i++) {
                func_8002EA98(i);
        }
        if (func_8002E694() != 0) {
            flagB = 1;
        }
        func_8002E94C(5);
        if (flagB == 1) {
            D_80137520 = 0x1B;
        }
        break;
    default:
        func_8002F634();
        break;
    }
    func_8003E904();
    if (D_80137520 >= 27) {
        return D_8013755C + 1;
    }
    return 0;
}
