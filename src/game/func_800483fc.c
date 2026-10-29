typedef struct Info {
    short a;
    short b;
    char c;
} Info;

typedef struct Leaf {
    unsigned char pad0[8];
    int value;
} Leaf;

typedef struct Item {
    unsigned char pad0[0x10];
    Leaf *leaf;
} Item;

typedef struct Group {
    int pad0;
    Item **items;
} Group;

typedef struct Entry {
    unsigned char pad0[0xC];
    unsigned char kind;
    unsigned char sub;
    unsigned char flag;
    unsigned char pad0F;
    unsigned char pad10[4];
    int value;
    unsigned char pad18[0x90];
    float scale;
    short s_ac;
    short s_ae;
    unsigned char pad_b0[0x20];
} Entry;

extern int D_801796F8;
extern int D_80179968;
extern Entry *D_80179924;
extern Entry D_8018C980[16];
extern unsigned char D_80179760[16][0x1C];
extern int D_8007C910;
extern Group *D_8013D658[];

extern int func_80051178(int a, void *b, Info *c);
extern void func_8005DD70(int a, void *b, int c, float d, int e, int f, int g, int h);
extern void func_80049E20(void);
extern int func_8005AAF0(int a, int b, int c);

void func_800483FC(void) {
    Info info;
    int pad[2];
    int i;
    Item **items;
    Item *it;
    Leaf *lf;

    D_801796F8 = 0;
    for (i = 0; i < 16; i++) {
        info.a = 10;
        info.b = 0;
        info.c = 0;
        func_80051178(D_8007C910, D_80179760[i], &info);
        D_80179924 = &D_8018C980[i];
        D_80179924->sub = 0;
        D_80179924->kind = D_80179924->sub;
        items = D_8013D658[D_80179924->kind]->items;
        it = items[D_80179924->sub + 3];
        lf = it->leaf;
        D_80179924->value = lf->value;
        D_80179924->scale = 1.0f;
        D_80179924->s_ac = 0;
        D_80179924->s_ae = 0;
        D_80179924->flag = 1;
        func_8005DD70(D_8007C910, D_80179760[i], D_80179924->value, 1.0f, 0, 0x40, 0, 0);
    }
    func_80049E20();
    D_80179968 = func_8005AAF0(D_8007C910, 0, 0);
}
