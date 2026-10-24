typedef struct RuntimeRecord {
    unsigned char bytes[0x148];
} RuntimeRecord;

typedef struct Descriptor {
    RuntimeRecord *record;
    float zero;
    float first;
    float second;
    unsigned char flag0;
    unsigned char flag1;
    signed short index;
    signed short count;
    unsigned char pad16[2];
    unsigned int first_word;
    unsigned int second_word;
    unsigned int zero_word;
    unsigned char pad24[4];
    unsigned long long pair;
    signed short enabled;
} Descriptor;

extern unsigned char *D_80126BF0;

void func_80037760(Descriptor *descriptor, int index, float first,
                   float second, unsigned int first_word,
                   unsigned int second_word) {
    descriptor->record =
        (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;
    descriptor->flag0 = 0;
    descriptor->flag1 = 0;
    descriptor->index = index;
    descriptor->count = 0;
    descriptor->first = first;
    descriptor->second = second;
    descriptor->zero = 0.0f;
    descriptor->first_word = first_word;
    descriptor->second_word = second_word;
    descriptor->zero_word = 0;
    descriptor->pair = 0;
    descriptor->enabled = 1;
}
