typedef struct RuntimeRecord {
    unsigned char bytes[0x148];
} RuntimeRecord;

typedef struct Orbit {
    RuntimeRecord *record;
    float height;
    float angle;
    float distance;
    unsigned char first;
    unsigned char second;
    signed short target;
    unsigned short kind;
    unsigned char pad16[2];
    unsigned int active;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned char pad24[4];
    unsigned long long timer;
    signed short enabled;
} Orbit;

extern unsigned char *D_80126BF0;

void func_800376C0(Orbit *orbit, int target, unsigned short kind, float angle, float distance, float height) {
    if (target < 0) {
        orbit->target = target;
        orbit->record = 0;
        return;
    }
    orbit->record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + target;
    orbit->height = height;
    orbit->angle = angle;
    orbit->distance = distance;
    orbit->first = 0;
    orbit->second = 0;
    orbit->target = target;
    orbit->kind = kind;
    orbit->active = 1;
    orbit->unk1C = 0;
    orbit->unk20 = 0;
    orbit->timer = 0;
    orbit->enabled = 1;
}
