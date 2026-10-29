#define NULL 0
typedef struct Entry {
    unsigned int id;
    unsigned char *dest;
} Entry;

typedef struct RuntimeData {
    unsigned char pad0[0x7C8C2];
    short head;
    short tail;
    unsigned char pad7C8C6[0x7C8E4 - 0x7C8C6];
    unsigned char count;
    unsigned char pad7C8E5[0x7C8E8 - 0x7C8E5];
    unsigned char *tableA;
    unsigned char *tableB;
    unsigned char pad7C8F0[0x7C92C - 0x7C8F0];
    unsigned char *assets[(0x9673C - 0x7C92C) / 4];
    Entry *values[40];
} RuntimeData;

extern RuntimeData *D_80126BF0;
extern unsigned char D_8022E600[];
extern unsigned char D_801E5E00[];
extern unsigned char *func_800014D8(unsigned int id, unsigned char *dest);

void func_8000C1D4(void) {
    unsigned char i;
    int pad[2];
    Entry *entry;
    Entry **slot;
    unsigned int limit;
    unsigned int id;

    for (i = 0; i < 40; i++) {
        slot = &D_80126BF0->values[i];
        if (*slot != NULL) {
            entry = *slot;
            for (;;) {
                id = entry->id;
                if (id & 0x20000000) {
                    while (D_80126BF0->head == D_80126BF0->tail) {
                    }
                }
                if (entry->dest == (unsigned char *)0) {
                    D_80126BF0->tableA = (unsigned char *)(((unsigned int)D_80126BF0->tableA + 7) & ~7);
                    D_80126BF0->assets[entry->id & 0x0FFFFFFF] = D_80126BF0->tableA;
                    limit = (unsigned int)D_8022E600 + 0x13A000;
                    D_80126BF0->tableA = func_800014D8(entry->id & 0x0FFFFFFF, D_80126BF0->tableA);
                    if (limit < (unsigned int)D_80126BF0->tableA) {
                        while (1) {
                        }
                    }
                } else if (entry->dest == (unsigned char *)1) {
                    D_80126BF0->tableB = (unsigned char *)(((unsigned int)D_80126BF0->tableB + 7) & ~7);
                    D_80126BF0->assets[entry->id & 0x0FFFFFFF] = D_80126BF0->tableB;
                    limit = (unsigned int)D_801E5E00 + 0x48800;
                    D_80126BF0->tableB = func_800014D8(entry->id & 0x0FFFFFFF, D_80126BF0->tableB);
                    if (limit < (unsigned int)D_80126BF0->tableB) {
                        while (1) {
                        }
                    }
                } else {
                    D_80126BF0->assets[id & 0x0FFFFFFF] = entry->dest;
                    func_800014D8(entry->id & 0x0FFFFFFF, entry->dest);
                }
                if (entry->id & 0x40000000) {
                    entry++;
                    break;
                }
                entry++;
            }
            *slot = NULL;
        }
    }
    D_80126BF0->count = 0;
}
