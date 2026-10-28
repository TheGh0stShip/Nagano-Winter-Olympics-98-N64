typedef struct Param {
    struct Param *next;
    int delta;
    short type;
    short moredata;
    int data;
} Param;

typedef struct Filter {
    void *source;
    void *handler;
    int (*setParam)(struct Filter *filter, int paramID, void *param);
} Filter;

typedef struct PVoice {
    unsigned char pad0[0xC];
    Filter *envmixer;
    unsigned char pad10[0xC8];
    int offset;
} PVoice;

typedef struct Voice {
    unsigned char pad0[8];
    PVoice *pvoice;
    unsigned char padC[0xE];
    short unk1A;
} Voice;

typedef struct Synth {
    unsigned char pad0[0x1C];
    int paramSamples;
} Synth;


extern Param *func_800554D0(void);

void func_80051E00(Synth *drvr, Voice *voice, int value) {
    Param *update;

    if (voice->pvoice) {
        update = func_800554D0();
        if (update) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 14;
            update->data = value;
            update->next = 0;
            update->moredata = voice->unk1A;
            voice->pvoice->envmixer->setParam(voice->pvoice->envmixer, 3, update);
        }
    }
}
