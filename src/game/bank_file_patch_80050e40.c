typedef struct WaveTable {
    unsigned char *base;
    int len;
    unsigned char type;
    unsigned char flags;
    unsigned char pad[2];
    void *loop;
    void *book;
} WaveTable;

typedef struct Sound {
    void *envelope;
    void *keyMap;
    WaveTable *wavetable;
    unsigned char samplePan;
    unsigned char sampleVolume;
    unsigned char flags;
} Sound;

typedef struct Instrument {
    unsigned char volume;
    unsigned char pan;
    unsigned char priority;
    unsigned char flags;
    unsigned char pad4[0xA];
    short soundCount;
    Sound *soundArray[1];
} Instrument;

typedef struct Bank {
    short instCount;
    unsigned char flags;
    unsigned char pad3;
    unsigned char pad4[4];
    Instrument *percussion;
    Instrument *instArray[1];
} Bank;

typedef struct BankFile {
    short revision;
    short bankCount;
    Bank *bankArray[1];
} BankFile;

typedef struct SeqData {
    unsigned char *offset;
    int len;
} SeqData;

typedef struct SeqFile {
    short revision;
    short seqCount;
    SeqData seqArray[1];
} SeqFile;

static void _bnkfPatchBank(Bank *bank, int offset, int table);
static void _bnkfPatchInst(Instrument *inst, int offset, int table);
static void _bnkfPatchSound(Sound *s, int offset, int table);
static void _bnkfPatchWaveTable(WaveTable *w, int offset, int table);

void func_80051048(SeqFile *file, unsigned char *base) {
    int i;

    for (i = 0; i < file->seqCount; i++) {
        file->seqArray[i].offset += (int)base;
    }
}

void func_80050F44(BankFile *file, unsigned char *table) {
    int offset = (int)file;
    int woffset = (int)table;
    int i;

    if (file->revision != 0x4231) {
        return;
    }
    for (i = 0; i < file->bankCount; i++) {
        file->bankArray[i] = (Bank *)((unsigned char *)file->bankArray[i] + offset);
        if (file->bankArray[i]) {
            _bnkfPatchBank(file->bankArray[i], offset, woffset);
        }
    }
}

static void _bnkfPatchBank(Bank *bank, int offset, int table) {
    int i;

    if (bank->flags) {
        return;
    }
    bank->flags = 1;
    if (bank->percussion) {
        bank->percussion = (Instrument *)((unsigned char *)bank->percussion + offset);
        _bnkfPatchInst(bank->percussion, offset, table);
    }
    for (i = 0; i < bank->instCount; i++) {
        bank->instArray[i] = (Instrument *)((unsigned char *)bank->instArray[i] + offset);
        if (bank->instArray[i]) {
            _bnkfPatchInst(bank->instArray[i], offset, table);
        }
    }
}

static void _bnkfPatchInst(Instrument *inst, int offset, int table) {
    int i;

    if (inst->flags) {
        return;
    }
    inst->flags = 1;
    for (i = 0; i < inst->soundCount; i++) {
        inst->soundArray[i] = (Sound *)((unsigned char *)inst->soundArray[i] + offset);
        _bnkfPatchSound(inst->soundArray[i], offset, table);
    }
}

static void _bnkfPatchSound(Sound *s, int offset, int table) {
    if (s->flags) {
        return;
    }
    s->flags = 1;
    s->envelope = (unsigned char *)s->envelope + offset;
    s->keyMap = (unsigned char *)s->keyMap + offset;
    s->wavetable = (WaveTable *)((unsigned char *)s->wavetable + offset);
    _bnkfPatchWaveTable(s->wavetable, offset, table);
}

static void _bnkfPatchWaveTable(WaveTable *w, int offset, int table) {
    if (w->flags) {
        return;
    }
    w->flags = 1;
    w->base += table;
    if (w->type == 0) {
        w->book = (unsigned char *)w->book + offset;
        if (w->loop) {
            w->loop = (unsigned char *)w->loop + offset;
        }
    } else if (w->type == 1) {
        if (w->loop) {
            w->loop = (unsigned char *)w->loop + offset;
        }
    }
}
