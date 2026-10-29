typedef struct { unsigned short btn; unsigned short b2; char pad4[4]; unsigned short held; unsigned short ha; char padC[2]; } Pad;
typedef struct { unsigned char id; char pad1; unsigned short btn; unsigned short held; short dur; short time; } Rec;
typedef struct { char pad0[0x7C8F6]; Pad pads[4]; } Game;
extern Game *D_80126BF0;
extern unsigned char D_80136190[4];
extern unsigned char D_80136194[4];
extern Rec D_80136198[4][16];
extern short D_80136418[4];
extern unsigned short D_80136420[4];
extern void func_8001A980(unsigned char);
extern void func_8001AA14(unsigned char);
extern void func_800596EC(const char *, ...);

void func_8001A590(void) {
    unsigned char i;
    unsigned char j;

    for (i = 0; i < 4; i++) {
        D_80136420[i]++;
        D_80136418[i]++;
        if (D_80136418[i] >= 0x7FFE) {
            D_80136418[i] = 0;
        }
        if (D_80136420[i] >= 0x1F) {
            D_80136418[i] = 0;
        }
        if (D_80136418[i] == 0 && D_80136194[i] == 1) {
            func_8001A980(i);
        }
        if (D_80126BF0->pads[i].btn == 0 && D_80126BF0->pads[i].held == 0) continue;
        {
            if (D_80136198[i][D_80136190[i]].btn != D_80126BF0->pads[i].btn || D_80136198[i][D_80136190[i]].held != D_80126BF0->pads[i].held || D_80126BF0->pads[i].b2 != 0 || D_80126BF0->pads[i].ha != 0) {
                D_80136194[i] = 1;
                D_80136420[i] = 0;
                D_80136190[i]++;
                func_8001AA14(i);
                D_80136198[i][D_80136190[i]].dur = 0;
                D_80136198[i][D_80136190[i]].id = D_80136190[i];
                D_80136198[i][D_80136190[i]].time = D_80136418[i];
                D_80136198[i][D_80136190[i]].btn = D_80126BF0->pads[i].btn;
                D_80136198[i][D_80136190[i]].held = D_80126BF0->pads[i].held;
                func_800596EC("[ player %d ]", i);
                func_800596EC("\n");
                for (j = 0; j < 16; j++) func_800596EC("%6d", D_80136198[i][j].id);
                func_800596EC("\n");
                for (j = 0; j < 16; j++) func_800596EC("%6x", D_80136198[i][j].btn);
                func_800596EC("\n");
                for (j = 0; j < 16; j++) func_800596EC("%6x", D_80136198[i][j].held);
                func_800596EC("\n");
                for (j = 0; j < 16; j++) func_800596EC("%6d", D_80136198[i][j].dur);
                func_800596EC("\n");
                for (j = 0; j < 16; j++) func_800596EC("%6d", D_80136198[i][j].time);
                func_800596EC("\n");
            } else if (D_80126BF0->pads[i].btn != 0 || D_80126BF0->pads[i].held != 0) {
                if (D_80136198[i][D_80136190[i]].dur < 0x7FFF) {
                    D_80136198[i][D_80136190[i]].dur++;
                }
                D_80136420[i] = 0;
            }
        }
    }
}
