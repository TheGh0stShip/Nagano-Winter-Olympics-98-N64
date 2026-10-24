typedef struct RuntimeEntry {
    short state;
    unsigned char pad_02[0x12A];
    unsigned int value;
} RuntimeEntry;

extern unsigned char *D_80126BF0;
extern unsigned char D_80137555;

void func_8002E6C8(void) {
    RuntimeEntry *entry = (RuntimeEntry *)(D_80126BF0 + 0x80F20);

    if (D_80137555 != 11) {
        entry->value = 0;
        entry->state = 0;
    }
}
