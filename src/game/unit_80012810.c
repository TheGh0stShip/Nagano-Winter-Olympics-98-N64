typedef struct OSMesgQueue {
    void *mtqueue;
    void *fullqueue;
    int validCount;
    int first;
    int msgCount;
    void **msg;
} OSMesgQueue;

typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern int osTvType;
extern int osRecvMesg(OSMesgQueue *, void **, int);
extern unsigned int osGetCount(void);
extern unsigned long long osGetTime(void);

unsigned long long D_80134DF0;
unsigned long long D_80134DF8;
unsigned long long D_80134E00;
unsigned long long D_80134E08;
extern float D_80134E10;
extern float D_80134E14;
extern float D_8006E5F4;
extern int D_8006E5F0;

void func_800128F0(float value);
void func_80012CC8(DisplayCommand **list, unsigned int color, float progress, int y);
void func_80012C14(DisplayCommand **list, float spacing);

void func_80012810(OSMesgQueue *queue) {
    unsigned int start;
    unsigned int end;

    if (queue->validCount >= queue->msgCount) {
        osRecvMesg(queue, 0, 1);
    }
    osRecvMesg(queue, 0, 1);
    start = osGetCount();
    osRecvMesg(queue, 0, 1);
    end = osGetCount();
    func_800128F0((osTvType == 0 ? 50.0 : 60.0) * (end - start));
}

void func_800128F0(float value) {
    D_8006E5F4 = value;
}

void func_800128FC(int mode) {
    switch (mode) {
        case 0:
            D_80134DF0 = osGetTime();
            break;
        case 1:
            D_80134DF8 = osGetTime();
            D_80134E10 = D_80134DF8 - D_80134DF0;
            D_80134E10 = 1000.0 * D_80134E10 / (unsigned long long)D_8006E5F4;
            break;
        case 2:
            D_80134E00 = osGetTime();
            break;
        case 3:
            D_80134E08 = osGetTime();
            D_80134E14 = D_80134E08 - D_80134E00;
            D_80134E14 = 1000.0 * D_80134E14 / (unsigned long long)D_8006E5F4;
            break;
    }
}

void func_80012A78(DisplayCommand **list) {
    float spacing = 240 / D_8006E5F0;
    float ratio;

    DISPLAY_COMMAND((*list)++, 0xE7000000, 0);
    DISPLAY_COMMAND((*list)++, 0xBA001402, 0x00300000);
    DISPLAY_COMMAND((*list)++, 0xB6000000, 1);
    DISPLAY_COMMAND((*list)++, 0xB900031D, 0x0F0A4000);
    ratio = D_80134E10 / (16.67 * D_8006E5F0);
    func_80012CC8(list, 0x03C103C1, ratio, 0);
    ratio = D_80134E14 / (16.67 * D_8006E5F0);
    func_80012CC8(list, 0x001F001F, ratio, 4);
    func_80012C14(list, spacing);
    DISPLAY_COMMAND((*list)++, 0xE7000000, 0);
}

void func_80012C14(DisplayCommand **list, float spacing) {
    int i;

    DISPLAY_COMMAND((*list)++, 0xE7000000, 0);
    DISPLAY_COMMAND((*list)++, 0xF7000000, 0x00010001);
    for (i = 0; i <= D_8006E5F0; i++) {
        DISPLAY_COMMAND((*list)++,
                        0xF6000000 | ((((int)spacing * i + 40) & 0x3FF) << 14) | (220 << 2),
                        ((((int)spacing * i + 40) & 0x3FF) << 14) | (210 << 2));
    }
}

void func_80012CC8(DisplayCommand **list, unsigned int color, float progress, int y) {
    DISPLAY_COMMAND((*list)++, 0xE7000000, 0);
    if (progress < 1.0) {
        DISPLAY_COMMAND((*list)++, 0xF7000000, color);
        DISPLAY_COMMAND((*list)++,
                        0xF6000000 | (((unsigned int)(240.0f * progress + 40.0f) & 0x3FF) << 14) | (((y + 216) & 0x3FF) << 2),
                        (40 << 14) | (((y + 210) & 0x3FF) << 2));
        return;
    }
    DISPLAY_COMMAND((*list)++, 0xF7000000, 0x78017801);
    DISPLAY_COMMAND((*list)++, 0xF6000000 | (280 << 14) | (((y + 216) & 0x3FF) << 2),
                    (40 << 14) | (((y + 210) & 0x3FF) << 2));
}
