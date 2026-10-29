typedef struct Rec {
    unsigned short kind;
    unsigned short state;
    unsigned char pad4[8];
    float x;
    float y;
    float z;
    unsigned char pad18[0x114];
    int value;
    unsigned char pad130[8];
} Rec;

typedef struct Runtime {
    unsigned char pad0[0x3EF8];
    Rec recs[0x5F];
} Runtime;

typedef struct Blob112 {
    unsigned char bytes[0x112];
} Blob112;

typedef struct BlobC4 {
    unsigned char bytes[0xC4];
} BlobC4;

extern unsigned char *D_80126BF0;
extern unsigned char D_80137704;
extern char D_80072450[];
extern char D_800723BC[];
extern char D_8007258C[];
extern char D_80072558[];
extern int D_80072348[];
extern int D_80072378;
extern int D_800723E4;
extern int D_800723E0;
extern int D_80072428;
extern int D_80072434;
extern int D_80072438;
extern int D_800724A0[];
extern int D_800724D0;
extern int D_80072628[];
extern int D_80072440;
extern int D_80072444;
extern int D_80072550;
extern int D_80072554;
extern int D_80072538;
extern int D_80072540;

extern void func_80032E94(void);
extern void func_8000ED68(void *);
extern void func_8000EC50(void *);
extern void func_8002FD8C(void *, int, int, int);
extern void func_8002FD50(void *, int, int, int, int, int, int);
extern void func_800437A0(unsigned short, void *, int, unsigned short, unsigned short);

#define REC(i) (((Runtime *)(D_80126BF0 + 0x80000))->recs[i])

void func_800324C0(void) {
    short i;
    BlobC4 small;
    Blob112 big;

    for (i = 0; i < 0x5F; i++) {
        REC(i).kind = 0;
    }
    *(short *)(D_80126BF0 + 0x7F898) = 1;
    func_80032E94();
    if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
        func_800437A0(0x34, D_800723BC, D_80072348[D_80126BF0[0x90000 + 0x77EC]], 2, 1);
    } else {
        func_800437A0(0x34, D_800723BC, D_80072378, 2, 1);
    }
    REC(0x34).x = 63.8f;
    REC(0x34).y = -121.0f;
    i = 0x35;
    func_800437A0(0x35, D_80072450, D_800723E4, 1, 1);
    REC(i).x += 160.0f;
    REC(i).y = -22.0f;
    func_800437A0(0x36, D_80072450, D_800723E0, 1, 1);
    REC(i + 1).x += 160.0f;
    REC(i + 1).y = -222.0f;
    func_800437A0(0x37, D_80072450, D_80072428, 1, 1);
    REC(i + 2).x += 160.2f;
    REC(i + 2).y = -29.0f;
    REC(i + 2).z = 10.0f;
    i = 0x38;
    func_800437A0(0x38, D_80072450, D_80072434, 1, 1);
    REC(i).x += 160.0f;
    REC(i).y = -193.0f;
    if (D_80137704 == 0) {
        REC(i).kind = 0;
    } else if (D_80137704 == 1) {
        REC(i).kind = 1;
    }
    func_800437A0(0x39, D_80072450, D_80072438, 1, 1);
    REC(i + 1).x += 160.0f;
    REC(i + 1).y = -215.0f;
    *(int *)(D_80126BF0 + 0x886D4) = 0;
    i = 0x3B;
    if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
        func_800437A0(0x3B, D_80072450, D_800724A0[D_80126BF0[0x90000 + 0x77EC]], 1, 1);
    } else {
        func_800437A0(0x3B, D_80072450, D_800724D0, 1, 1);
    }
    REC(i).x = 28.0f;
    REC(i).y = -59.9f;
    if (D_80137704 == 0) {
        func_800437A0(0x3C, D_8007258C, D_80072628[D_80126BF0[0x90000 + 0x77F0]], 1, 1);
    } else if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
        func_8000ED68(&small);
        func_800437A0(0x3C, D_8007258C, D_80072628[small.bytes[1]], 1, 1);
    } else {
        func_8000EC50(&big);
        func_800437A0(0x3C, D_8007258C, D_80072628[big.bytes[1]], 1, 1);
    }
    REC(i + 1).x = 256.2f;
    REC(i + 1).y = -60.0f;
    i = 0x3D;
    func_800437A0(0x3D, D_80072450, D_80072440, 1, 1);
    REC(i).x += 160.0f;
    REC(i).y = -180.0f;
    func_800437A0(0x3E, D_80072450, D_80072444, 1, 0);
    REC(i + 1).x += 160.0f;
    REC(i + 1).y = -180.0f;
    func_800437A0(0x3F, D_80072450, D_80072444, 1, 0);
    REC(i + 2).x = REC(i + 1).x + 224.0f;
    REC(i + 2).y = -180.0f;
    i = 0x40;
    if (D_80126BF0[0x90000 + 0x77F1] == 0x14) {
        func_800437A0(0x40, D_80072558, D_80072550, 1, 1);
    } else {
        func_800437A0(0x40, D_80072558, D_80072554, 1, 1);
    }
    REC(i).x = 224.0f;
    REC(i).y -= 120.0f;
    func_8002FD8C(&REC(i), 0x7F, 0x7F, 0x7F);
    func_8002FD50(&REC(i), 0xAF, 0xAF, 0xAF, -10, 5, 10);
    func_800437A0(0x41, D_80072558, D_80072538, 1, 1);
    REC(i + 1).x = 224.0f;
    REC(i + 1).y -= 120.0f;
    func_8002FD8C(&REC(i + 1), 0x7F, 0x7F, 0x7F);
    func_8002FD50(&REC(i + 1), 0xAF, 0xAF, 0xAF, -10, 5, 10);
    func_800437A0(0x42, D_80072558, D_80072540, 1, 1);
    REC(i + 2).x = 96.0f;
    REC(i + 2).y -= 120.0f;
    func_8002FD8C(&REC(i + 2), 0x7F, 0x7F, 0x7F);
    func_8002FD50(&REC(i + 2), 0xAF, 0xAF, 0xAF, -10, 5, 10);
    func_800437A0(0x43, D_80072558, D_80072538, 1, 1);
    REC(i + 3).x = 96.0f;
    REC(i + 3).y -= 120.0f;
    func_8002FD8C(&REC(i + 3), 0x7F, 0x7F, 0x7F);
    func_8002FD50(&REC(i + 3), 0xAF, 0xAF, 0xAF, -10, 5, 10);
    for (i = 0; i < 0x5F; i++) {
        func_8002FD50(&REC(i), 0xAF, 0xAF, 0xAF, -10, 5, 10);
        func_8002FD8C(&REC(i), 0x7F, 0x7F, 0x7F);
    }
}
