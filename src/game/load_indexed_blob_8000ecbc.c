typedef struct Blob9C {
    unsigned int words[0x27];
} Blob9C;

extern Blob9C D_801336F8[];

void func_8000ECBC(unsigned char index, void *destination) {
    *(Blob9C *)destination = D_801336F8[index];
}
