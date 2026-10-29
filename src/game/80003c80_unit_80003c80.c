typedef struct MessageQueue {
    unsigned char data[0x18];
} MessageQueue;

typedef struct Thread {
    unsigned char data[0x1B0];
} Thread;

typedef struct OSTaskLike {
    unsigned char data[0x40];
} OSTaskLike;

typedef struct SchedTask {
    unsigned char pad0[0x8];
    int flags;
    void *framebuffer;
    OSTaskLike list;
    MessageQueue *queue;
    void *message;
} SchedTask;

typedef struct Scheduler {
    unsigned short unk0;
    short unk2;
    MessageQueue queue4;
    void *messages1C[0x50];
    MessageQueue queue15C;
    void *messages174[0x50];
    MessageQueue queue2B4;
    void *messages2CC[0x50];
    MessageQueue queue40C;
    void *messages424[0x50];
    MessageQueue queue564;
    void *messages57C[0x50];
    MessageQueue queue6BC;
    void *messages6D4[0x51];
    Thread thread818;
    Thread thread9C8;
    Thread threadB78;
    void *unkD28;
    SchedTask *unkD2C;
    SchedTask *unkD30;
    SchedTask *unkD34;
    void *unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    unsigned long long unkD48;
    unsigned long long unkD50;
    unsigned long long unkD58;
    unsigned long long unkD60;
} Scheduler;

extern unsigned long long D_8007C990;
extern int func_8004E540(MessageQueue *queue, void *msg, unsigned char flag);
extern int func_8004E2A0(MessageQueue *queue, void *msg, unsigned char flag);
extern void func_8005F3F0(void);
extern void func_80052320(void);
extern int func_8005B2C0(OSTaskLike *task);
extern unsigned long long func_8005B340(void);
extern void func_8004ED4C(OSTaskLike *task);
extern void func_8004EEDC(OSTaskLike *task);
extern unsigned long long func_8004F088(unsigned long long a, unsigned long long b);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);

typedef struct SchedClient {
    struct SchedClient *next;
    int value;
} SchedClient;

extern void *func_8005FF40(void);
extern void *func_800517B0(void);
extern void func_80052260(int flag);
extern void func_8005AE20(void *framebuffer);

typedef struct ViMode {
    unsigned char data[0x50];
} ViMode;

extern ViMode D_8007C9B0[];
extern unsigned char D_8012CBE0[];
extern unsigned char D_8012EBE0[];
extern unsigned char D_80130BE0[];
extern void func_8005A5D0(MessageQueue *queue, void **messages, int count);
extern void func_8005FA60(int priority);
extern void func_80052AB0(ViMode *mode);
extern void func_80052260(int flag);
extern void func_8005C840(MessageQueue *queue, int message, int retrace);
extern void func_80059390(int event, MessageQueue *queue, int message);
extern void func_80050A90(Thread *thread, int id, void (*entry)(void *), void *arg, void *stack, int priority);
extern void func_8005F810(Thread *thread);

void func_80003EB8(Scheduler *sc);
void func_80004088(Scheduler *sc);
void func_80004290(Scheduler *sc);
void func_80004038(Scheduler *sc, void *value);

void func_80003C80(Scheduler *sc, unsigned char mode, unsigned char numFields) {
    sc->unkD40 = 1;
    sc->unk0 = 1;
    sc->unkD2C = 0;
    sc->unkD30 = 0;
    sc->unkD34 = 0;
    sc->unkD28 = 0;
    sc->unkD3C = 0;
    sc->unkD38 = 0;
    sc->unk2 = 3;
    sc->unkD48 = 0;
    sc->unkD50 = 0;
    sc->unkD58 = 0;
    sc->unkD60 = 0;
    func_8005A5D0(&sc->queue2B4, sc->messages2CC, 0x50);
    func_8005A5D0(&sc->queue40C, sc->messages424, 0x50);
    func_8005A5D0(&sc->queue564, sc->messages57C, 0x50);
    func_8005A5D0(&sc->queue15C, sc->messages174, 0x50);
    func_8005A5D0(&sc->queue4, sc->messages1C, 0x50);
    func_8005A5D0(&sc->queue6BC, sc->messages6D4, 0x50);
    func_8005FA60(0xFE);
    func_80052AB0(&D_8007C9B0[mode]);
    func_80052260(1);
    func_8005C840(&sc->queue2B4, 0x29A, numFields);
    func_80059390(4, &sc->queue40C, 0x29B);
    func_80059390(9, &sc->queue564, 0x29C);
    func_80059390(14, &sc->queue2B4, 0x29D);
    func_80050A90(&sc->thread818, 0x13, (void (*)(void *))func_80003EB8, sc, D_8012CBE0, 0x78);
    func_8005F810(&sc->thread818);
    func_80050A90(&sc->thread9C8, 0x12, (void (*)(void *))func_80004088, sc, D_8012EBE0, 0x6E);
    func_8005F810(&sc->thread9C8);
    func_80050A90(&sc->threadB78, 0x11, (void (*)(void *))func_80004290, sc, D_80130BE0, 0x64);
    func_8005F810(&sc->threadB78);
}

void *func_80003EA0(Scheduler *sc) {
    return &sc->queue4;
}

void *func_80003EA8(Scheduler *sc) {
    return &sc->queue15C;
}

int func_80003EB0(Scheduler *sc) {
    return (int)sc->unkD38;
}

void func_80003EB8(Scheduler *sc) {
    int message = 0;

    while (1) {
        func_8004E540(&sc->queue2B4, &message, 1);
        switch (message) {
            case 666:
                func_80004038(sc, sc);
                break;
            case 669:
                func_80004038(sc, (unsigned char *)sc + 2);
                break;
        }
    }
}

extern unsigned int func_8004E680(unsigned int mask);

void func_80003F60(Scheduler *sc, SchedClient *client, MessageQueue *queue) {
    unsigned int lock = func_8004E680(1);

    client->value = (int)queue;
    client->next = (SchedClient *)sc->unkD28;
    sc->unkD28 = client;
    func_8004E680(lock);
}

void func_80003FB0(Scheduler *sc, SchedClient *target) {
    SchedClient *client = (SchedClient *)sc->unkD28;
    SchedClient *previous = 0;
    unsigned int mask = func_8004E680(1);

    while (client != 0) {
        if (client == target) {
            if (previous != 0) {
                previous->next = target->next;
            } else {
                sc->unkD28 = target->next;
            }
            break;
        }
        previous = client;
        client = client->next;
    }
    func_8004E680(mask);
}

void func_80004038(Scheduler *sc, void *value) {
    SchedClient *node = (SchedClient *)sc->unkD28;

    while (node != 0) {
        func_8004E2A0((MessageQueue *)node->value, value, 0);
        node = node->next;
    }
}

void func_80004088(Scheduler *sc) {
    void *msg = 0;
    SchedTask *task = 0;
    int state = 0;
    SchedTask *yielded;
    unsigned long long start;
    unsigned long long end;

    for (;;) {
        func_8004E540(&sc->queue4, &task, 1);
        func_8005F3F0();
        state = 0;
        yielded = sc->unkD2C;
        if (yielded != 0) {
            func_80052320();
            func_8004E540(&sc->queue40C, &msg, 1);
            if (func_8005B2C0(&yielded->list)) {
                state = 1;
            } else {
                state = 2;
            }
        }
        start = func_8005B340();
        sc->unkD30 = task;
        func_8004ED4C(&task->list);
        func_8004EEDC(&task->list);
        func_8004E540(&sc->queue40C, &msg, 1);
        sc->unkD30 = 0;
        sc->unkD58 = func_8004EF88(func_8004F088(func_8005B340() - start, 1000000), D_8007C990);
        if (sc->unkD34 != 0) {
            func_8004E2A0(&sc->queue6BC, &msg, 1);
        }
        if (state == 1) {
            sc->unkD60 += sc->unkD58;
            func_8004ED4C(&yielded->list);
            func_8004EEDC(&yielded->list);
        } else if (state == 2) {
            func_8004E2A0(&sc->queue40C, &msg, 1);
        }
        func_8004E2A0(task->queue, task->message, 1);
    }
}

void func_80004290(Scheduler *sc) {
    void *msg = 0;
    SchedTask *task;
    SchedClient client;
    unsigned long long start;

    for (;;) {
        func_8004E540(&sc->queue15C, &task, 1);
        while (func_8005FF40() == task->framebuffer || func_800517B0() == task->framebuffer) {
            func_80003F60(sc, &client, &sc->queue6BC);
            func_8004E540(&sc->queue6BC, &msg, 1);
            func_80003FB0(sc, &client);
        }
        if (sc->unkD30 != 0) {
            sc->unkD34 = task;
            func_8004E540(&sc->queue6BC, &msg, 1);
            sc->unkD34 = 0;
        }
        sc->unkD60 = 0;
        start = func_8005B340();
        sc->unkD2C = task;
        func_8004ED4C(&task->list);
        func_8004EEDC(&task->list);
        func_8004E540(&sc->queue40C, &msg, 1);
        sc->unkD2C = 0;
        sc->unkD48 = func_8004EF88(func_8004F088(func_8005B340() - start, 1000000), D_8007C990) - sc->unkD60;
        func_8004E540(&sc->queue564, &msg, 1);
        sc->unkD50 = func_8004EF88(func_8004F088(func_8005B340() - start, 1000000), D_8007C990);
        if (sc->unkD40 != 0) {
            func_80052260(0);
            sc->unkD40 = 0;
        }
        if (task->flags & 0x40) {
            func_8005AE20(task->framebuffer);
        }
        sc->unkD3C--;
        func_8004E2A0(task->queue, task->message, 1);
    }
}
