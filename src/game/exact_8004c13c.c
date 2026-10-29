typedef struct SoundRecord {
    unsigned char pad0[0x10];
    unsigned char active;
} SoundRecord;

typedef struct SoundSlot {
    unsigned char bytes[0x1C];
} SoundSlot;

extern SoundRecord *D_80179924;
extern unsigned char D_8017966C;
extern SoundSlot D_80179760[];
extern unsigned char *D_80179920;
extern void *D_8007C910;
extern int D_80179968;
extern int D_800736DC;
extern int D_800736E0;
extern void func_8005A730(void *, SoundSlot *, int);
extern void func_80051770(void *, int, int, int *);

void func_8004C13C(void) {
    unsigned char c;
    int value;
    int pad;

    if (D_80179924->active != 0) {
        func_8005A730(D_8007C910, &D_80179760[D_8017966C], 0);
    }
    c = *D_80179920++;
    value = c * 40;
    if (value == 0) {
        value = D_800736DC;
    }
    func_80051770(D_8007C910, D_80179968, 3, &value);
    c = *D_80179920++;
    value = c << 7;
    if (value == 0) {
        value = D_800736E0;
    }
    func_80051770(D_8007C910, D_80179968, 4, &value);
    if (D_80179924->active != 0) {
        func_8005A730(D_8007C910, &D_80179760[D_8017966C], D_80179924->active);
    }
}
