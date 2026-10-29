typedef struct Transform {
    unsigned char pad0[3];
    unsigned char index;
    float values[9];
} Transform;

typedef struct Record {
    unsigned char pad0[4];
    float values[9];
    unsigned char pad28[0x14];
} Record;

extern unsigned char *D_80126BF0;

void func_80012F20(Transform *src) {
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[0] = src->values[0];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[1] = src->values[1];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[2] = src->values[2];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[3] = src->values[3];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[4] = src->values[4];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[5] = src->values[5];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[6] = src->values[6];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[7] = src->values[7];
    ((Record *)(D_80126BF0 + 0x7D23C))[src->index].values[8] = src->values[8];
}
