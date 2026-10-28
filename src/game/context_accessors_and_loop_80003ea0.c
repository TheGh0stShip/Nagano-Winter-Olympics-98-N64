void *func_80003EA0(void *value) {
    return (char *)value + 4;
}

void *func_80003EA8(void *value) {
    return (char *)value + 0x15C;
}

int func_80003EB0(void *value) {
    return *(int *)((char *)value + 0xD38);
}

typedef struct Context {
    unsigned char pad0[2];
    unsigned char second[0x2B2];
    unsigned char queue[0x18];
} Context;

extern void func_8004E540(void *queue, void *message, int flags);
extern void func_80004038(Context *context, void *target);

void func_80003EB8(Context *context) {
    int message = 0;

    while (1) {
        func_8004E540(context->queue, &message, 1);
        switch (message) {
            case 666:
                func_80004038(context, context);
                break;
            case 669:
                func_80004038(context, context->second);
                break;
        }
    }
}
