typedef struct {
    short type;
    short visible;
    char pad4[8];
    float x;
    float y;
    char pad14[0x12C - 0x14];
    int tex;
    char pad130[8];
} T80033554;

typedef struct {
    char pad[0x83EF8];
    T80033554 objs[1];
} G80033554;

typedef struct {
    char pad[0x977F0];
    unsigned char count;
    unsigned char kind;
} H80033554;

typedef struct {
    unsigned char pad0;
    unsigned char count;
    unsigned char order[4];
    unsigned char names[20][9];
    unsigned char pad[2];
} BA80033554;

typedef struct {
    unsigned char pad0;
    unsigned char count;
    unsigned char names[30][9];
    unsigned char pad[2];
} BB80033554;

extern void func_80009358(short, unsigned short, void *);
extern void func_8000EC50(void *);
extern void func_8000ED68(void *);
extern int D_80072864[];
extern char D_80072998[];
extern G80033554 *D_80126BF0;
extern unsigned char D_80137704;
extern unsigned char D_801376D8[][9];

void func_80033554(void) {
    short row;
    short col;
    short count;
    unsigned char ch;
    int ten;
    int g;
    BA80033554 ba;
    BB80033554 bb;

    if (D_80137704 == 0) {
        count = ((H80033554 *)D_80126BF0)->count;
    } else if (D_80137704 == 1) {
        if (((H80033554 *)D_80126BF0)->kind == 0x14) {
            func_8000ED68(&ba);
            count = ba.count;
        } else {
            func_8000EC50(&bb);
            count = bb.count;
        }
    }
    for (row = 0; row < count; row++) {
        for (col = 0; col < 8; col++) {
            g = D_80137704;
            if (g == 0) {
                ch = D_801376D8[row][col];
            } else if (g == 1u) {
                if (((H80033554 *)D_80126BF0)->kind == 0x14) {
                    ch = ba.names[ba.order[row]][col];
                } else {
                    ch = bb.names[row][col];
                }
            }
            ten = (ten & 0) | 10;
            func_80009358(row * 8 + col, ten, D_80072998);
            D_80126BF0->objs[row * 8 + col].x = col * 9.0f + 164.2f;
            D_80126BF0->objs[row * 8 + col].y = (27.0f - row * 19.0f) - 120.0f;
            if (row >= 2) {
                D_80126BF0->objs[row * 8 + col].y -= 0.1f * (row - 1);
            }
            D_80126BF0->objs[row * 8 + col].visible = 1;
            if (ch >= 'A' && ch <= 'Z') {
                D_80126BF0->objs[row * 8 + col].tex = D_80072864[ch - 0x37];
                D_80126BF0->objs[row * 8 + col].type = ten;
            } else if (ch >= 'a' && ch <= 'z') {
                D_80126BF0->objs[row * 8 + col].tex = D_80072864[ch - 0x3D];
                D_80126BF0->objs[row * 8 + col].type = ten;
            } else {
                switch (ch) {
                case '.':
                    D_80126BF0->objs[row * 8 + col].tex = D_80072864[63];
                    D_80126BF0->objs[row * 8 + col].type = ten;
                    break;
                case '-':
                    D_80126BF0->objs[row * 8 + col].tex = D_80072864[64];
                    D_80126BF0->objs[row * 8 + col].type = ten;
                    break;
                default:
                    D_80126BF0->objs[row * 8 + col].type = 0;
                    break;
                }
            }
        }
    }
}
