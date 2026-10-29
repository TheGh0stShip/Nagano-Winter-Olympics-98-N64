typedef struct Runtime2EC64 {
    unsigned char pad[8];
    float x;
    float y;
    float z;
    unsigned char rest[0x414];
} Runtime2EC64;

extern unsigned char *D_80126BF0;
extern float D_80137538[6];
extern unsigned char D_80137555;
extern float D_80071E10[];
extern void func_8002ED78(float out[3]);

void func_8002EC64(unsigned char index, unsigned char addOffset) {
    register Runtime2EC64 *record =
        (Runtime2EC64 *)(D_80126BF0 + 0x802A8) + index;
    float offset[3];

    D_80137538[3] = record->x;
    D_80137538[4] = record->y;
    D_80137538[5] = record->z;
    D_80137538[0] = record->x;
    D_80137538[1] = record->y;
    D_80137538[2] = record->z;
    if (addOffset != 0) {
        func_8002ED78(&offset[1]);
        D_80137538[0] += offset[1];
        D_80137538[1] += offset[2];
        D_80137538[2] += offset[3];
    }
    D_80137538[1] += 200.0f * D_80071E10[D_80137555];
    D_80137538[4] += 160.0f * D_80071E10[D_80137555];
}
