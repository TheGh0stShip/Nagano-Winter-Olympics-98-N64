typedef struct Blob9C {
    unsigned int words[0x27];
} Blob9C;

extern Blob9C D_801336F8[];

void func_8000F2B4(unsigned char index, const void *source) {
    D_801336F8[index] = *(const Blob9C *)source;
}
