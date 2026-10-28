typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;

typedef struct ThreadContext {
    u64 at, v0, v1, a0, a1, a2, a3;
    u64 t0, t1, t2, t3, t4, t5, t6, t7;
    u64 s0, s1, s2, s3, s4, s5, s6, s7;
    u64 t8, t9, gp, sp, s8, ra;
    u64 lo, hi;
    u32 sr, pc, cause, badvaddr, rcp;
    u32 fpcsr;
    f64 fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    f64 fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} ThreadContext;

typedef struct Thread {
    struct Thread *next;
    s32 priority;
    struct Thread **queue;
    struct Thread *tlnext;
    u16 state;
    u16 flags;
    s32 id;
    s32 fp;
    ThreadContext context;
} Thread;

extern Thread *D_8007C94C;
extern void func_8004FAE0(void);
extern u32 func_8005BFD0(void);
extern void func_8005BFF0(u32 mask);

void func_80050A90(Thread *thread, s32 id, void (*entry)(void *),
                   void *argument, void *stack, s32 priority) {
    register u32 saveMask;
    u32 interruptMask;

    thread->id = id;
    thread->priority = priority;
    thread->next = 0;
    thread->queue = 0;
    thread->context.pc = (u32)entry;
    thread->context.a0 = (s32)argument;
    thread->context.sp = (s64)(s32)stack - 16;
    thread->context.ra = (s32)func_8004FAE0;
    interruptMask = 0x003FFF01;
    thread->context.sr = 0x0000FF03;
    thread->context.rcp = (interruptMask & 0x003F0000) >> 16;
    thread->context.fpcsr = 0x01000800;
    thread->fp = 0;
    thread->state = 1;
    thread->flags = 0;

    saveMask = func_8005BFD0();
    thread->tlnext = D_8007C94C;
    D_8007C94C = thread;
    func_8005BFF0(saveMask);
}
