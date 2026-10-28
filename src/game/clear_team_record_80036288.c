typedef struct Record {
    short flag;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[8];
} Record;

typedef struct Team {
    unsigned char pad0[0xA];
    short base;
} Team;

typedef struct Lane {
    short state;
    unsigned char pad2[0x96];
} Lane;

extern unsigned char *D_80126BF0;
extern Team D_80137720;
extern Lane D_801377C6[];

void func_80036288(unsigned char index) {
    ((Record *)(D_80126BF0 + 0x83EF8) + D_80137720.base)[index].value = 0;
    ((Record *)(D_80126BF0 + 0x83EF8) + D_80137720.base)[index].flag = 0;
    D_801377C6[index].state = 0;
}
