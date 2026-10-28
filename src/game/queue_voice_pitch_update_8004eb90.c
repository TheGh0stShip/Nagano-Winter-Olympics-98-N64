typedef struct Param {
    struct Param *next;
    int delta;
    short type;
    short pad;
    int data;
    int moredata;
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
extern int func_800553C8(Synth *drvr, int time);

void func_8004EB90(Synth *drvr, Voice *voice, short pitch, int time) {
    Param *update;

    if (voice->pvoice) {
        update = func_800554D0();
        if (update) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 11;
            update->data = pitch;
            update->moredata = func_800553C8(drvr, time);
            update->next = 0;
            voice->pvoice->envmixer->setParam(voice->pvoice->envmixer, 3, update);
        }
    }
}
