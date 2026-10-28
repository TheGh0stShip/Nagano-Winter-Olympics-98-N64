typedef struct ClockRecord {
    unsigned char active;
    unsigned char pad1[3];
    float elapsed;
    unsigned long long timestamp;
} ClockRecord;

typedef struct Position {
    short pad0;
    short x;
    short y;
} Position;

extern ClockRecord D_80136610[];
extern unsigned long long func_8005B340(void);
extern float func_800542B8(unsigned long long value);
extern unsigned long long func_800541B8(float value);
extern void func_8001C998(Position *position, unsigned char index, unsigned long long ticks, int x, int y);

void func_8001C8F0(unsigned char index) {
    ClockRecord *record = &D_80136610[index];
    Position *position;

    if (!record->active) {
        record->active = 1;
    }
    record->elapsed = func_800542B8(func_8005B340() - record->timestamp);
    func_8001C998(position, index, func_800541B8(record->elapsed), position->x, position->y);
}
