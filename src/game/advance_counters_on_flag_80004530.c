typedef struct Context {
    unsigned char pad[0xD38];
    unsigned int counter;
    int frames;
} Context;

typedef struct Message {
    unsigned char pad[8];
    int flags;
} Message;

extern int func_8004E680(int value);
extern void func_8004E2A0(void *target, Message *message, int value);

void func_80004530(Context *context, void *target, Message *message) {
    int value;

    if (message->flags & 0x40) {
        if (++context->counter >= 3) {
            context->counter = 0;
        }
        value = func_8004E680(1);
        context->frames++;
        func_8004E680(value);
    }
    func_8004E2A0(target, message, 1);
}
