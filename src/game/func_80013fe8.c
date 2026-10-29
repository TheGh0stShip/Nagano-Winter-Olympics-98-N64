typedef struct Sound {
    int words[26];
} Sound;

extern unsigned char D_80135720;
extern unsigned char D_80135721;
extern unsigned short D_80135722;
extern unsigned short D_80135724;
extern unsigned char D_80135726;
extern unsigned short D_80135728;
extern unsigned short D_8013572A;
extern unsigned char D_8013572C;
extern unsigned char D_8013572D;
extern unsigned short D_8013572E;
extern unsigned char D_80135730;
extern unsigned char D_80135731;
extern unsigned char D_80135732;
extern unsigned char D_80135733;
extern unsigned char D_80063998[];
extern unsigned char D_80135370[];
extern Sound D_80135580[];
extern Sound D_80135790[];
extern unsigned char D_80135744[];
extern unsigned char D_80135930[];
extern void func_800163B8(void);
extern void func_8000C190(void *);
extern void func_800138F0(void *);

int func_80013FE8(void) {
    unsigned char i;

    D_80135722 = 0;
    D_80135724 = 0;
    D_80135720 = 0;
    D_80135721 = 16;
    D_80135726 = 18;
    D_80135728 = 0;
    D_8013572A = 0;
    D_8013572C = 0;
    D_8013572D = 1;
    D_8013572E = 255;
    D_80135730 = 1;
    D_80135731 = 0;
    D_80135732 = 0;
    D_80135733 = 0;
    func_800163B8();
    func_8000C190(D_80063998);
    func_800138F0(D_80135370);
    for (i = 0; i < 4; i++) {
        D_80135580[i] = D_80135790[i];
        D_80135744[i] = D_80135930[i];
    }
    if (D_80135744[0] && D_80135744[1] && D_80135744[2] && D_80135744[3]) {
        return 1;
    }
    return 0;
}
