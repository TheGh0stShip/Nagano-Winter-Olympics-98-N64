typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Block78 {
    u32 words[0x1E];
} Block78;

typedef struct Record428 {
    u8 pad00[0x2C];
    u16 value;
    u8 flags[3];
    u8 pad31[7];
    Block78 first;
    Block78 second;
    u8 pad128[0x300];
} Record428;

typedef struct Record150 {
    u8 pad00[0x2C];
    u16 value;
    u8 flags[3];
    u8 pad31[7];
    Block78 first;
    Block78 second;
    u8 pad128[0x28];
} Record150;

typedef struct Record148 {
    u8 pad00[0x30];
    u16 value;
    u8 flags[3];
    u8 pad35[3];
    Block78 first;
    Block78 second;
    u8 pad128[0x20];
} Record148;

typedef struct Record138 {
    u8 pad00[0x30];
    u16 value;
    u8 flags[3];
    u8 pad35[3];
    Block78 first;
    Block78 second;
    u8 pad128[0x10];
} Record138;

typedef struct SmallRecord148 {
    u8 pad00[6];
    u16 value;
    u8 flags[3];
    u8 pad0B[0x13D];
} SmallRecord148;

extern u8 *D_80126BF0;

void func_8002FDB0(u16 value, u8 flag) {
    Record428 *records428 = (Record428 *)(D_80126BF0 + 0x802A8);
    Record150 *records150 = (Record150 *)(D_80126BF0 + 0x83868);
    SmallRecord148 *small = (SmallRecord148 *)(D_80126BF0 + 0x7F898);
    Record148 *records148 = (Record148 *)(D_80126BF0 + 0x8B2C0);
    Record138 *records138 = (Record138 *)(D_80126BF0 + 0x83EF8);
    short i;

    i = 0;
    do {
        i++;
        small++;
        small[-1].value = value;
        small[-1].flags[2] = flag;
        small[-1].flags[1] = flag;
        small[-1].flags[0] = flag;
    } while (i < 2);
    i = 0;
    do {
        records428->value = value;
        records428->flags[2] = flag;
        records428->flags[1] = flag;
        records428->flags[0] = flag;
        records428->second = records428->first;
        i++;
        records428++;
    } while (i < 10);
    i = 0;
    do {
        records150->value = value;
        records150->flags[2] = flag;
        records150->flags[1] = flag;
        records150->flags[0] = flag;
        records150->second = records150->first;
        i++;
        records150++;
    } while (i < 5);
    i = 0;
    do {
        records148->value = value;
        records148->flags[2] = flag;
        records148->flags[1] = flag;
        records148->flags[0] = flag;
        records148->second = records148->first;
        i++;
        records148++;
    } while (i < 0x58);
    i = 0;
    do {
        records138->value = value;
        records138->flags[2] = flag;
        records138->flags[1] = flag;
        records138->flags[0] = flag;
        records138->second = records138->first;
        i++;
        records138++;
    } while (i < 0x5F);
}

void func_8002FFA8(u16 value, u8 flag) {
    Record428 *records428 = (Record428 *)(D_80126BF0 + 0x802A8);
    Record150 *records150 = (Record150 *)(D_80126BF0 + 0x83868);
    SmallRecord148 *small = (SmallRecord148 *)(D_80126BF0 + 0x7F898);
    Record148 *records148 = (Record148 *)(D_80126BF0 + 0x8B2C0);
    Record138 *records138 = (Record138 *)(D_80126BF0 + 0x83EF8);
    short i;

    i = 0;
    do {
        i++;
        small++;
        small[-1].value = value;
        small[-1].flags[2] = flag;
        small[-1].flags[1] = flag;
        small[-1].flags[0] = flag;
    } while (i < 2);
    i = 0;
    do {
        records428->value = value;
        records428->flags[2] = flag;
        records428->flags[1] = flag;
        records428->flags[0] = flag;
        records428->first = records428->second;
        i++;
        records428++;
    } while (i < 10);
    i = 0;
    do {
        records150->value = value;
        records150->flags[2] = flag;
        records150->flags[1] = flag;
        records150->flags[0] = flag;
        records150->first = records150->second;
        i++;
        records150++;
    } while (i < 5);
    i = 0;
    do {
        records148->value = value;
        records148->flags[2] = flag;
        records148->flags[1] = flag;
        records148->flags[0] = flag;
        records148->first = records148->second;
        i++;
        records148++;
    } while (i < 0x58);
    i = 0;
    do {
        records138->value = value;
        records138->flags[2] = flag;
        records138->flags[1] = flag;
        records138->flags[0] = flag;
        records138->first = records138->second;
        i++;
        records138++;
    } while (i < 0x5F);
}
