typedef struct StreamRecord {
    unsigned char pad0[0x9A];
    unsigned short limit;
    unsigned char pad9C[2];
    unsigned char duration;
    unsigned char pad9F;
    unsigned short increment;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004C804(void) {
    unsigned char **stream = &D_80179920;
    StreamRecord *volatile *record = &D_80179924;
    unsigned char duration = **stream;
    StreamRecord *current;

    (*record)->duration = duration;
    (*stream)++;
    if (duration != 0) {
        current = *record;
        current->increment = current->limit / current->duration;
    }
}
