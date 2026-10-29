typedef struct StreamPairStateB {
    unsigned char pad0[0x34];
    short first;
    unsigned char pad36[0xC];
    short second;
    unsigned char pad44[0x20];
    unsigned char counter;
    unsigned char pad65[3];
    unsigned char *next;
} StreamPairStateB;

extern unsigned char *D_80179920;
extern StreamPairStateB *D_80179924;

void func_8004CFA0(void) {
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
