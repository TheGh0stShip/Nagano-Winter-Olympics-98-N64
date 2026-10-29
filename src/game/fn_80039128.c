typedef struct Entry {
    int pad0;
    int first;
    int pad8[2];
    int second;
} Entry;

extern unsigned char D_80072B00;
extern int D_801378B0;
extern int D_801378E8;
extern int D_80137920;
extern int D_80137958;
extern int D_80137990;
extern int D_801379C8;
extern int D_80137A00;
extern int D_80137A38;
extern int D_80137A98;
extern int D_80137AD0;
extern int D_80137B08;
extern int D_80137B68;
extern int D_80137BA0;
extern int D_80137BD8;
extern int D_80137C38;
extern int D_80137CF8;
extern int D_80137D30;
extern Entry D_80137D70;
extern Entry D_80137D98;
extern Entry D_80137DC0;
extern Entry D_80137A70;
extern Entry D_80137B40;
extern Entry D_80137C10;
extern Entry D_80137C70;
extern Entry D_80137CD0;

void func_80039128(int mode) {
    if (mode != D_80072B00) {
        D_80072B00 = mode;
        D_801378B0 = 0;
        D_801378E8 = 0;
        D_80137920 = 0;
        D_80137958 = 0;
        D_80137990 = 0;
        D_801379C8 = 0;
        D_80137A00 = 0;
        D_80137A38 = 0;
        D_80137A98 = 0;
        D_80137AD0 = 0;
        D_80137B08 = 0;
        D_80137B68 = 0;
        D_80137BA0 = 0;
        D_80137BD8 = 0;
        D_80137C38 = 0;
        D_80137CF8 = 0;
        D_80137D30 = 0;
        D_80137D70.first = -1;
        D_80137D70.second = 0;
        D_80137D98.second = 0;
        D_80137D98.first = -1;
        D_80137DC0.second = 0;
        D_80137DC0.first = -1;
        D_80137A70.second = 0;
        D_80137A70.first = -1;
        D_80137B40.second = 0;
        D_80137B40.first = -1;
        D_80137C10.second = 0;
        D_80137C10.first = -1;
        D_80137C70.second = 0;
        D_80137C70.first = -1;
        D_80137CD0.second = 0;
        D_80137CD0.first = -1;
    }
}
