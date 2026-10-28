typedef struct RuntimeData {
    unsigned char pad0[0x7C8E4];
    unsigned char count;
    unsigned char pad7C8E5[0x9673C - 0x7C8E5];
    int values[40];
} RuntimeData;
extern RuntimeData *D_80126BF0;
void func_8000C190(int *arg0, int arg1) {
    RuntimeData *data = D_80126BF0;
    arg1 = (int)arg0;
    arg0 = &data->values[data->count];
    data->count++;
    *arg0 = arg1;
}
