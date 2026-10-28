typedef unsigned long long u64;
typedef int s32;

typedef struct Timer {
    struct Timer *next;
    struct Timer *prev;
    u64 interval;
    u64 value;
    void *queue;
    void *message;
} Timer;

extern Timer *D_8007DA20;
extern u64 func_8005B648(Timer *timer);
extern void func_8005B5D4(u64 time);

s32 func_8005E3B0(Timer *timer, u64 countdown, u64 interval, void *queue,
                  void *message) {
    u64 time;

    timer->next = 0;
    timer->prev = 0;
    timer->interval = interval;
    timer->value = countdown != 0 ? countdown : interval;
    timer->queue = queue;
    timer->message = message;
    time = func_8005B648(timer);
    if (D_8007DA20->next == timer) {
        func_8005B5D4(time);
    }
    return 0;
}
