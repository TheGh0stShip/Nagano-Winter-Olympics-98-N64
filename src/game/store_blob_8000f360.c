typedef struct BlobC4 {
    unsigned char bytes[0xC4];
} BlobC4;

extern BlobC4 D_80133F48;

void func_8000F360(const void *source) {
    D_80133F48 = *(const BlobC4 *)source;
}
