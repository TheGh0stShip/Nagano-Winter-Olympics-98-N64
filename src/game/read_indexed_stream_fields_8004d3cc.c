typedef struct StreamRecord {
    unsigned char pad0[0xB0];
    unsigned char first[3];
    unsigned char second[3];
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004D3CC(void) {
    unsigned char index = *D_80179920;

    D_80179920++;
    D_80179924->first[index] = *D_80179920;
    D_80179920++;
    D_80179924->second[index] = *D_80179920;
    D_80179920++;
}
