typedef struct BlobC4 {
    unsigned char bytes[0xC4];
} BlobC4;

extern BlobC4 D_80133F48;

void func_8000ED68(void *destination) {
    *(BlobC4 *)destination = D_80133F48;
}
