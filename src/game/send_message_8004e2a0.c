typedef unsigned int u32;
typedef int s32;

typedef struct Thread {
    struct Thread *next;
    s32 priority;
    struct Thread **queue;
    unsigned char padC[4];
    unsigned short state;
} Thread;

typedef struct MessageQueue {
    Thread *mtqueue;
    Thread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **messages;
} MessageQueue;

extern Thread *D_8007C950;
extern u32 func_8005BFD0(void);
extern void func_8005BFF0(u32 mask);
extern void func_8004F80C(Thread **queue);
extern Thread *func_8004F954(Thread **queue);
extern void func_8005F810(Thread *thread);

s32 func_8004E2A0(MessageQueue *queue, void *message, s32 flag) {
    register u32 mask;
    register s32 index;

    mask = func_8005BFD0();
    while (queue->validCount >= queue->msgCount) {
        if (flag == 1) {
            D_8007C950->state = 8;
            func_8004F80C(&queue->fullqueue);
        } else {
            func_8005BFF0(mask);
            return -1;
        }
    }
    index = (queue->first + queue->validCount) % queue->msgCount;
    queue->messages[index] = message;
    queue->validCount++;
    if (queue->mtqueue->next != 0) {
        func_8005F810(func_8004F954(&queue->mtqueue));
    }
    func_8005BFF0(mask);
    return 0;
}
