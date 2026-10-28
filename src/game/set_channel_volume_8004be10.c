typedef struct Channel {
    unsigned int word;
    unsigned char pad4[0x36];
    unsigned short volume;
    unsigned char pad3C[0xB];
    unsigned char flag;
} Channel;

extern unsigned char *D_80179920;
extern Channel *D_80179924;

void func_8004BE10(void) {
    unsigned char value = *D_80179920++;
    Channel *channel = D_80179924;

    if (channel->word >> 24) {
        channel->volume = value * (channel->word / 0x1000000);
    } else {
        channel->volume = value << 8;
    }
    D_80179924->flag = 0;
}
