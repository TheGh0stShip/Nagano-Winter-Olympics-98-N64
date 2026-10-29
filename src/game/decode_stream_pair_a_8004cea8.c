typedef struct StreamPairStateA {
    unsigned char pad0[0x32];
    short first;
    unsigned char pad34[0xC];
    short second;
    unsigned char pad42[0x1C];
    unsigned char counter;
    unsigned char pad5F;
    unsigned char *next;
} StreamPairStateA;

extern unsigned char *D_80179920;
extern StreamPairStateA *D_80179924;

void func_8004CEA8(void) {
    int limit;

    limit = *D_80179920++;

    D_80179924->counter++;
    if (limit != 0) {
        limit = D_80179924->counter - limit;
        if (limit == 0) {
            goto finish;
        }
    }

    D_80179924->second += *(signed char *)D_80179920;
    D_80179920++;
    D_80179924->first += *(signed char *)D_80179920 * 8;
    D_80179920++;
    D_80179920 = D_80179924->next;
    return;

finish:
    D_80179924->second = 0;
    D_80179924->first = D_80179924->second;
    D_80179920 += 2;
}
