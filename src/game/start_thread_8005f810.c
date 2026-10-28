typedef unsigned int u32;

typedef struct Thread {
    struct Thread *next;
    int priority;
    struct Thread **queue;
    unsigned char padC[4];
    unsigned short state;
} Thread;

extern Thread *D_8007C948;
extern Thread *D_8007C950;
extern u32 func_8005BFD0(void);
extern void func_8005BFF0(u32 mask);
extern void func_8004F90C(Thread **queue, Thread *thread);
extern Thread *func_8004F954(Thread **queue);
extern void func_8004F964(void);
extern void func_8004F80C(Thread **queue);

void func_8005F810(Thread *thread) {
    register u32 mask = func_8005BFD0();

    switch (thread->state) {
        case 8:
            thread->state = 2;
            func_8004F90C(&D_8007C948, thread);
            break;
        case 1:
            if (thread->queue == 0 || thread->queue == &D_8007C948) {
                thread->state = 2;
                func_8004F90C(&D_8007C948, thread);
            } else {
                thread->state = 8;
                func_8004F90C(thread->queue, thread);
                func_8004F90C(&D_8007C948, func_8004F954(thread->queue));
            }
            break;
    }

    if (D_8007C950 == 0) {
        func_8004F964();
    } else if (D_8007C950->priority < D_8007C948->priority) {
        D_8007C950->state = 2;
        func_8004F80C(&D_8007C948);
    }
    func_8005BFF0(mask);
}
