typedef struct Blob100 {
    unsigned char bytes[0x100];
} Blob100;

extern Blob100 D_80133E48;

void func_8000F310(const void *source) {
    D_80133E48 = *(const Blob100 *)source;
}
