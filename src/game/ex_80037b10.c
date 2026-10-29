typedef struct Rec {
    int pad0;
    int pad4;
    int active;
} Rec;

extern unsigned char D_80072AF8;
extern unsigned char D_80137DF4;
extern Rec D_80137D70;
extern Rec D_80137D98;
extern Rec D_80137A70;
extern Rec D_80137B40;
extern Rec D_80137C10;
extern Rec D_80137C70;
extern Rec D_80137CD0;
extern Rec D_80137DC0;
extern void func_80037C70(Rec *, float);

void func_80037B10(void) {
    if (D_80072AF8 != 0) {
        func_80037C70(&D_80137D70, 0.0f);
        D_80137D70.active = 0;
        func_80037C70(&D_80137D98, 0.0f);
        D_80137D98.active = 0;
        func_80037C70(&D_80137A70, 0.0f);
        D_80137A70.active = 0;
        func_80037C70(&D_80137B40, 0.0f);
        D_80137B40.active = 0;
        func_80037C70(&D_80137C10, 0.0f);
        D_80137C10.active = 0;
        func_80037C70(&D_80137C70, 0.0f);
        D_80137C70.active = 0;
        func_80037C70(&D_80137CD0, 0.0f);
        D_80137CD0.active = 0;
        if (D_80137DF4 == 0) {
            func_80037C70(&D_80137DC0, 0.0f);
            D_80137DC0.active = 0;
        }
    }
}
