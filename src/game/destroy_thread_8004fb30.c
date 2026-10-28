typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;

typedef struct Thread {
    struct Thread *next;
    s32 priority;
    struct Thread **queue;
    struct Thread *tlnext;
    u16 state;
} Thread;

extern Thread *D_8007C94C;
extern Thread *D_8007C950;
extern u32 func_8005BFD0(void);
extern void func_8005BFF0(u32 mask);
extern void func_8004FAF0(Thread **queue, Thread *thread);
extern void func_8004F964(void);

void func_8004FB30(Thread *thread) {
    register u32 mask;
    register Thread *previous;
    register Thread *next;

    mask = func_8005BFD0();
    if (thread == 0) {
        thread = D_8007C950;
    } else if (thread->state != 1) {
        func_8004FAF0(thread->queue, thread);
    }
    if (D_8007C94C == thread) {
        D_8007C94C = D_8007C94C->tlnext;
    } else {
        previous = D_8007C94C;
        while ((next = previous->tlnext) != 0) {
            if (next == thread) {
                previous->tlnext = thread->tlnext;
                break;
            }
            previous = next;
        }
    }
    if (thread == D_8007C950) {
        func_8004F964();
    }
    func_8005BFF0(mask);
}
