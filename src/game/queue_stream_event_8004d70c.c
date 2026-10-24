typedef struct StreamEvent {
    unsigned short value;
    unsigned char type;
    unsigned char argument;
    short amount;
} StreamEvent;

extern unsigned short D_800745B8[];
extern unsigned char D_80179930;
extern StreamEvent D_80179938[];

void func_8004D70C(unsigned char type, unsigned char index,
                   unsigned char argument, short amount) {
    int count = D_80179930;
    StreamEvent *event;

    if (count < 8) {
        event = &D_80179938[count];
        event->type = type;
        event->value = D_800745B8[index];
        event->argument = argument;
        event->amount = amount;
        D_80179930 = count + 1;
    }
}
