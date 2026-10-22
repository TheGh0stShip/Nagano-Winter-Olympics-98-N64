typedef struct Blob112 {
    unsigned char bytes[0x112];
} Blob112;

extern Blob112 D_801335E0;

void func_8000EC50(void *destination) {
    *(Blob112 *)destination = D_801335E0;
}
