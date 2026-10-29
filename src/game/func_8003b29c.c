typedef struct Game {
    char pad[0x977EC];
    unsigned char unk977EC;
    char pad2[2];
    unsigned char unk977EF;
} Game;

extern void func_800375F0(int id, unsigned short kind, float x, float y, float z, float w);
extern void func_8003889C(float scale, float y, int x, int id, int flag);
extern void func_80038A38(char *str, float x, float y, int id);
extern void func_80039004(int id, float x, float y, int a, int b, int c);
extern float func_80039ACC(float t);
extern void func_8003EB80(int id, int show);
extern void func_8003EC10(int id, float x, float y, unsigned short color);
extern int D_80072AEC;
extern char D_06002370[];
extern int D_80072B64[];
extern Game *D_80126BF0;
extern char D_801376D8[][9];
extern unsigned char D_80137DE9;
extern unsigned char D_80137DEA;
extern float D_80137DEC;
extern unsigned short D_80137DF0;
extern unsigned char D_80137DF5;
extern float D_801381F8;
extern unsigned char D_80138218;
extern unsigned char D_80138219;
extern short D_8013821C;

void func_8003B29C(int id, unsigned short color) {
    float y;
    float y1;
    float x;
    float v;

    y = (int)(-93.0f - func_80039ACC(D_801381F8) * 120.0f);
    if (D_80137DF5 == 0) {
        y -= 100.0f;
    }
    if (D_80138218 != 0) {
        func_8003889C(1.0f, y, 0xDC, id, 0);
        id++;
        y1 = y - 1.0f;
        func_8003EC10(id, -96.0f, y1, color);
        id++;
        func_80038A38(D_801376D8[D_80126BF0->unk977EF], -83.0f, y - 2.0f, id);
        id++;
        func_8003EB80(id, 1);
        id++;
        func_8003EC10(id, 16.0f, y1, color);
        id++;
        func_8003EC10(id, -120.0f, y1, color);
        id++;
        if (D_8013821C >= 0 && D_8013821C < 0x10) {
            func_80039004(id, 40.0f, y1, 7, D_80072B64[D_8013821C], color & D_80138219);
        } else {
            func_8003EB80(id, 0);
        }
        id++;
        if (D_80137DE9 != 0) {
            func_80039004(id, 70.0f, y1, D_80072AEC, (int)D_06002370, 1);
        } else {
            func_8003EB80(id, 0);
        }
        id++;
        if (D_80137DEA != 0) {
            x = 136.0f;
            if (D_80137DF0 != 0x400 && D_80137DF0 != 0x600) {
                if (D_80137DF0 != 0x900) {
                    if (D_80137DF0 == 0xA00) {
                        x = 133.0f;
                    }
                } else {
                    x = 122.0f;
                    if (D_80126BF0->unk977EC == 5) {
                        x = 114.0f;
                    }
                }
            } else {
                x = 128.0f;
            }
            v = D_80137DEC;
            if (v < 0.0f) {
                v = 0.0f;
            }
            func_800375F0(id, D_80137DF0, x, y1, 7.0f, v);
            func_8003EB80(id, 1);
        } else {
            func_8003EB80(id, 0);
        }
    }
}
