typedef struct StreamRecord {
    unsigned char pad0[0x70];
    unsigned char stream_depth;
    unsigned char pad71[3];
    unsigned char *nested_stream;
    unsigned char *saved_stream;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004D0B4(void) {
    switch (D_80179924->stream_depth) {
    case 0:
        D_80179924->stream_depth++;
        break;
    case 1:
        D_80179924->stream_depth++;
        D_80179924->saved_stream = D_80179920;
        D_80179920 = D_80179924->nested_stream;
        break;
    case 2:
        D_80179924->stream_depth--;
        D_80179920 = D_80179924->saved_stream;
        break;
    }
}
