typedef struct ClockRecord {
    unsigned char active;
    unsigned char pad1[3];
    float elapsed;
    long long timestamp;
} ClockRecord;

extern ClockRecord D_80136610[];
extern long long func_8005B340(void);

void func_8001C89C(unsigned char index, unsigned char arg1,
                   unsigned char arg2) {
    struct {
        int pad;
        ClockRecord *record;
    } local;

    local.record = &D_80136610[index];

    local.record->active = 0;
    local.record->elapsed = 0.0f;
    local.record->timestamp = func_8005B340();
}
