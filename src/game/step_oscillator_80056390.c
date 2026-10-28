typedef struct Oscillator {
    unsigned char pad0[0x10];
    float rate;
    float phase;
    unsigned char pad18[4];
    float depth;
} Oscillator;

float func_80056390(Oscillator *osc, int samples) {
    float value;

    osc->phase += osc->rate * samples;
    osc->phase = osc->phase > 2.0 ? osc->phase - 4.0 : osc->phase;
    value = osc->phase;
    if (value < 0.0f) {
        value = -value;
    }
    value = value - 1.0;
    return osc->depth * value;
}
