typedef struct Record {
    short flag;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[8];
} Record;

typedef struct Team {
    unsigned char count;
    unsigned char pad1[9];
    short base;
    unsigned char mode;
} Team;

typedef struct Lane {
    unsigned char pad0[0x96];
    unsigned short state;
} Lane;

extern unsigned char *D_80126BF0;
extern Team D_80137720;
extern Lane D_80137730[];
extern void func_800359C0(unsigned char index);

void func_80035854(void) {
    short i;

    if (D_80137720.mode == 1U) {
        for (i = 0; i < D_80137720.count; i++) {
            if (D_80137730[i].state != 0) {
                ((Record *)(D_80126BF0 + 0x83EF8) + D_80137720.base)[i].flag = 1;
                func_800359C0(i);
            } else {
                ((Record *)(D_80126BF0 + 0x83EF8) + D_80137720.base)[i].flag = 0;
                ((Record *)(D_80126BF0 + 0x83EF8) + D_80137720.base)[i].value = 0;
            }
        }
    }
}
