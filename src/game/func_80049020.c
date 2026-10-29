typedef struct {
    int id;
    char pad4[0xB2];
    unsigned char vol;
    unsigned char step;
    char padB8[0xD0 - 0xB8];
} Voice;
typedef struct {
    unsigned char unk0[3];
    unsigned char rate;
    unsigned char unk4[2];
} Fade;
extern void func_80049F88(void);
extern void func_8004A050(int);
extern Voice *D_80179924;
extern unsigned char D_80179930;
extern Fade D_80179938[];
extern Voice D_8018C980[16];

void func_80049020(unsigned int id) {
    int i;
    Voice *v;

    if (D_80179938[D_80179930].rate != 0) {
        for (i = 0; i < 4; i++) {
            D_80179924 = &D_8018C980[i * 4 + 0];
            if (id == (D_80179924->id & 0x7FFF)) {
                D_80179924->vol = 0xFF;
                D_80179924->step = 0x100 / D_80179938[D_80179930].rate;
                if (D_80179924->step == 0) {
                    D_80179924->step = 1;
                }
            }
            D_80179924 = &D_8018C980[i * 4 + 1];
            if (id == (D_80179924->id & 0x7FFF)) {
                D_80179924->vol = 0xFF;
                D_80179924->step = 0x100 / D_80179938[D_80179930].rate;
                if (D_80179924->step == 0) {
                    D_80179924->step = 1;
                }
            }
            D_80179924 = &D_8018C980[i * 4 + 2];
            if (id == (D_80179924->id & 0x7FFF)) {
                D_80179924->vol = 0xFF;
                D_80179924->step = 0x100 / D_80179938[D_80179930].rate;
                if (D_80179924->step == 0) {
                    D_80179924->step = 1;
                }
            }
            D_80179924 = &D_8018C980[i * 4 + 3];
            if (id == (D_80179924->id & 0x7FFF)) {
                D_80179924->vol = 0xFF;
                D_80179924->step = 0x100 / D_80179938[D_80179930].rate;
                if (D_80179924->step == 0) {
                    D_80179924->step = 1;
                }
            }
        }
    } else if (id < 0x100) {
        if (id == (D_8018C980[0].id & 0x7FFF)) {
            func_80049F88();
        }
    } else {
        for (i = 0; i < 16; i++) {
            if (id == (D_8018C980[i].id & 0x7FFF)) {
                func_8004A050(i);
            }
        }
    }
}
