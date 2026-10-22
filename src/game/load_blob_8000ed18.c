typedef struct Blob100 {
    unsigned char bytes[0x100];
} Blob100;

extern Blob100 D_80133E48;

void func_8000ED18(void *destination) {
    *(Blob100 *)destination = D_80133E48;
}
