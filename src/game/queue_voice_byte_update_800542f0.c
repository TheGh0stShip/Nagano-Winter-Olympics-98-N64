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
} Voice;

typedef struct Synth {
    unsigned char pad0[0x1C];
    int paramSamples;
} Synth;


extern Param *func_800554D0(void);

void func_800542F0(Synth *drvr, Voice *voice, unsigned char value) {
    Param *update;

    if (voice->pvoice) {
        update = func_800554D0();
        if (update) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 12;
            update->data = value;
            update->next = 0;
            voice->pvoice->envmixer->setParam(voice->pvoice->envmixer, 3, update);
        }
    }
}
