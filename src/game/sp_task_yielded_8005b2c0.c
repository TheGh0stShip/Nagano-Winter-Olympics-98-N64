typedef struct TaskHeader {
    unsigned int type;
    unsigned int flags;
} TaskHeader;

extern unsigned int func_8005F3E0(void);

int func_8005B2C0(TaskHeader *task) {
    unsigned int status;
    int yielded;

    status = func_8005F3E0();
    if (status & 0x100) {
        yielded = 1;
    } else {
        yielded = 0;
    }
    if (status & 0x80) {
        task->flags |= yielded;
        task->flags &= ~2;
    }
    return yielded;
}
