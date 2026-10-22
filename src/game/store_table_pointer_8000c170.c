typedef struct RuntimeState {
    unsigned char pad[0x7C8EC];
    void *table;
} RuntimeState;

extern RuntimeState *D_80126BF0;
extern unsigned char D_801E5E00[];

void func_8000C170(void) {
    D_80126BF0->table = D_801E5E00;
}
