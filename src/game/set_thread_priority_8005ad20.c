typedef unsigned int u32;
typedef int s32;

typedef struct Thread {
    struct Thread *next;
    s32 priority;
    struct Thread **queue;
    unsigned char padC[4];
    unsigned short state;
} Thread;

extern Thread *D_8007C950;
extern Thread *D_8007C948;
extern u32 func_8005BFD0(void);
extern void func_8005BFF0(u32 mask);
extern void func_8004FAF0(Thread **queue, Thread *thread);
extern void func_8004F90C(Thread **queue, Thread *thread);
extern void func_8004F80C(Thread **queue);

void func_8005AD20(Thread *thread, s32 priority) {
    register u32 mask;

    mask = func_8005BFD0();
    if (thread == 0) {
        thread = D_8007C950;
    }
    if (thread->priority != priority) {
        thread->priority = priority;
        if (thread != D_8007C950 && thread->state != 1) {
            func_8004FAF0(thread->queue, thread);
            func_8004F90C(thread->queue, thread);
        }
        if (D_8007C950->priority < D_8007C948->priority) {
            D_8007C950->state = 2;
            func_8004F80C(&D_8007C948);
        }
    }
    func_8005BFF0(mask);
}
