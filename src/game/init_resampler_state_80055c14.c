typedef struct Resampler {
    unsigned char filter[0x14];
    void *first;
    void *second;
    unsigned char pad1C[0x14];
    void *state;
    unsigned char control[8];
    int unk3C;
    int unk40;
    int unk44;
} Resampler;

extern unsigned char D_800586FC[];
extern unsigned char D_80058050[];
extern void func_8005A3D0(void *filter, void *handler, void *setParam, int type);
extern void *func_8005F420(unsigned char *file, int line, void *heap, int num, int size);

void func_80055C14(Resampler *r, void *(*init)(void *control), void *heap) {
    func_8005A3D0(r, D_800586FC, D_80058050, 0);
    r->first = func_8005F420(0, 0, heap, 1, 32);
    r->second = func_8005F420(0, 0, heap, 1, 32);
    r->state = init(r->control);
    r->unk3C = 0;
    r->unk40 = 1;
    r->unk44 = 0;
}
