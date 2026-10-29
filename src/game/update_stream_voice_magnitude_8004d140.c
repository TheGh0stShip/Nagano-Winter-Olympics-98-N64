typedef struct StreamVoiceState {
    unsigned int flags;
    unsigned char pad4[0xC];
    unsigned char magnitude;
} StreamVoiceState;

typedef struct VoiceRecord {
    unsigned char bytes[28];
} VoiceRecord;

extern unsigned char *D_80179920;
extern StreamVoiceState *D_80179924;
extern unsigned char D_80179684[];
extern unsigned char D_8017966C;
extern VoiceRecord D_80179760[];
extern void *D_8007C910;
extern void func_8005A730(void *driver, VoiceRecord *voice,
                          unsigned char magnitude);

void func_8004D140(void) {
    int offset_index;
    unsigned char magnitude;

    offset_index = (D_80179924->flags & 0x7FFF) < 0x100U ? 0 : 1;

    magnitude = *D_80179920++;
    magnitude += D_80179684[offset_index];
    if (magnitude >= 0x80) {
        magnitude = 0x7F;
    }
    if (magnitude == D_80179924->magnitude) {
        return;
    }
    D_80179924->magnitude = magnitude;
    func_8005A730(D_8007C910, &D_80179760[D_8017966C], magnitude);
}
