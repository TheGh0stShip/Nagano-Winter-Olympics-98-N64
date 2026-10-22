typedef struct RuntimeState {
    unsigned char pad[0x7C8E8];
    void *table;
} RuntimeState;

extern RuntimeState *D_80126BF0;
extern unsigned char D_8022E600[];

void func_8000C150(void) {
    D_80126BF0->table = D_8022E600;
}
