typedef signed int s32;

typedef struct Resampler {
    char filter[0x14];
    void *state;
    float ratio;
    s32 unity_pitch;
    float delta;
    s32 first;
    s32 motion;
    void *control_list;
    void *control_tail;
} Resampler;

extern void func_8005A3D0(void *filter, void *handler, void *set_param, s32 type);
extern void *func_8005F420(s32 unused_0, s32 unused_1, void *heap,
                           s32 count, s32 size);
extern void func_80057E3C(void);
extern void func_80057D50(void);

void func_80055B8C(Resampler *resampler, void *heap) {
    func_8005A3D0(resampler, func_80057E3C, func_80057D50, 1);
    resampler->state = func_8005F420(0, 0, heap, 1, 0x20);
    resampler->first = 1;
    resampler->control_tail = 0;
    resampler->unity_pitch = 0;
    resampler->motion = 0;
    resampler->control_list = 0;
    resampler->delta = 0.0f;
    resampler->ratio = 1.0f;
}
