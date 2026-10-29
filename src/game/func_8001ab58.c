typedef struct {
    unsigned short a;
    unsigned short b;
    signed char c;
    char pad5;
} Seg;
typedef struct {
    short pad0;
    unsigned short b;
    unsigned short c;
    short pad6;
    short unk8;
} Ent;
extern Seg *D_8006F420[];
extern unsigned char D_8006F418[];
extern unsigned char D_80136190[];
extern Ent D_80136198[][16];
extern short D_80136430[][50];
extern char D_8007E6E0[], D_8007E6EC[], D_8007E6F0[], D_8007E700[], D_8007E70C[], D_8007E718[], D_8007E724[], D_8007E730[];
extern char D_8007E734[], D_8007E74C[], D_8007E758[], D_8007E768[], D_8007E77C[], D_8007E790[];
extern void func_800596EC(char *, ...);
extern unsigned char func_8001AF40(unsigned char);
extern int func_8001AFD4(unsigned char);

void func_8001AB58(unsigned char arg0) {
    unsigned char i;
    int ii;
    Seg *seg;
    unsigned char cur;
    unsigned char cnt;
    short acc;
    short d;
    unsigned char next;
    unsigned char r;

    for (i = 0; D_8006F420[i] != (Seg *)0xFF; i++) {
        ii = i;
        func_800596EC(D_8007E6E0, ii);
        acc = 0;
        cnt = 0;
        func_800596EC(D_8007E6EC);
        seg = D_8006F420[i];
        cur = D_80136190[arg0];
        while (1) {
            func_800596EC(D_8007E6F0, cur);
            func_800596EC(D_8007E700, seg->a);
            func_800596EC(D_8007E70C, D_80136198[arg0][cur].b);
            func_800596EC(D_8007E718, seg->b);
            func_800596EC(D_8007E724, D_80136198[arg0][cur].c);
            func_800596EC(D_8007E730);
            if (seg->a == 0xFF) {
                next = cur + 1;
                if (next >= 16) next = 0;
                d = D_80136198[arg0][D_80136190[arg0]].unk8 - D_80136198[arg0][next].unk8;
                if (seg->c < d) {
                    d -= seg->c;
                } else {
                    d = 0;
                }
                r = func_8001AF40(arg0);
                if (r != 0xFF) {
                    if (D_8006F418[i] >= (short)(acc + d)) {
                        D_80136430[arg0][r] = D_8006F418[i] - (short)(acc + d);
                    } else {
                        D_80136430[arg0][r] = 0;
                    }
                }
                func_800596EC(D_8007E734, ii);
                func_800596EC(D_8007E74C, r);
                func_800596EC(D_8007E758, D_80136430[arg0][r]);
                func_800596EC(D_8007E768, d);
                func_800596EC(D_8007E77C, acc);
                func_800596EC(D_8007E790);
                break;
            }
            if ((D_80136198[arg0][cur].b & seg->a) || (D_80136198[arg0][cur].c & seg->b)) {
                cnt = 0;
                if (D_80136198[arg0][cur].b != seg->a || D_80136198[arg0][cur].c != seg->b) {
                    acc += seg->c;
                }
                seg++;
            } else {
                if (((seg->a & 0xF00) && (D_80136198[arg0][cur].b & 0xF00)) || ((seg->b & 0xF00) && (D_80136198[arg0][cur].c & 0xF00))) {
                    cnt++;
                } else {
                    cnt += 2;
                }
                if (cnt >= 2) break;
            }
            cur = func_8001AFD4(cur);
        }
    }
}
