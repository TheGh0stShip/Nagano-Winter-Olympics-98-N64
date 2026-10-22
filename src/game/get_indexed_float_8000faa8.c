typedef struct FloatRecord {
    unsigned char pad[0x9C];
} FloatRecord;

extern FloatRecord D_8013376C[];

float func_8000FAA8(unsigned char index) {
    return *(float *)&D_8013376C[index];
}
