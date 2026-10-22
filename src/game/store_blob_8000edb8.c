typedef struct Blob112 {
    unsigned char bytes[0x112];
} Blob112;

extern Blob112 D_801335E0;

void func_8000EDB8(const void *source) {
    D_801335E0 = *(const Blob112 *)source;
}
