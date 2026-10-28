typedef struct Fx {
    unsigned char pad[0x2C];
} Fx;

typedef struct AuxBus {
    unsigned char filter[0x20];
    Fx fx[1];
} AuxBus;

typedef struct Synth {
    unsigned char pad0[0x30];
    void *mainBus;
    AuxBus *auxBus;
} Synth;

extern void func_80055E00(Fx *fx, void *config, void *heap);
extern int func_80056C84(void *filter, int paramID, void *param);
extern int func_80056240(void *filter, int paramID, void *param);

Fx *func_8005F9C0(Synth *s, short bus, void *config, void *heap) {
    func_80055E00(&s->auxBus[bus].fx[0], config, heap);
    func_80056C84(&s->auxBus[bus].fx[0], 1, &s->auxBus[bus]);
    func_80056240(s->mainBus, 2, &s->auxBus[bus].fx[0]);
    return &s->auxBus[bus].fx[0];
}
