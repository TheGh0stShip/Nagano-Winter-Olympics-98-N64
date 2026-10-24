typedef struct StreamRecord {
    unsigned char pad0[0x58];
    unsigned short value;
    unsigned char pad5A;
    unsigned char flag;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;
extern unsigned char D_8017966C;

extern void func_8004A250(unsigned char value);

void func_8004C27C(void) {
    register StreamRecord **record = &D_80179924;
    register unsigned char **stream = &D_80179920;
    unsigned char *position;
    unsigned char value;

    (*record)->flag = 0;
    position = *stream;
    value = *position;
    *stream = position + 1;
    (*record)->value = value << 8;
    func_8004A250(D_8017966C);
}
