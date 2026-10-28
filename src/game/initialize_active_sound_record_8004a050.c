typedef struct SoundRecord {
    unsigned int state;
    unsigned char flag;
    unsigned char pad5[9];
    unsigned char active;
    unsigned char mode;
    unsigned char pad10[0x9C];
    short first;
    short second;
    unsigned char padB0[0x20];
} SoundRecord;

typedef struct SoundSlot {
    unsigned char bytes[0x1C];
} SoundSlot;

extern SoundRecord D_8018C980[];
extern SoundRecord *D_80179924;
extern SoundSlot D_80179760[];
extern void *D_8007C910;
extern void func_8004EB90(void *, SoundSlot *, int, int);

void func_8004A050(int index) {
    D_80179924 = &D_8018C980[index];
    D_80179924->state = 0;
    D_80179924->flag = 0;
    if (D_80179924->active != 0) {
        D_80179924->mode = 2;
        D_80179924->first = 0;
        D_80179924->second = 0;
        func_8004EB90(D_8007C910, &D_80179760[index], 0, 5000);
    }
}
