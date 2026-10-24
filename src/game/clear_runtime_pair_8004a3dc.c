typedef struct RuntimePair {
    short value;
    unsigned char enabled;
} RuntimePair;

extern volatile RuntimePair D_80179678;

void func_8004A3DC(void) {
    D_80179678.value = 0;
    D_80179678.enabled = 0;
}
