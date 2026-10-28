typedef struct Entry {
    int first;
    int second;
    int third;
} Entry;

extern void func_80039004(int value, int first, int second, int size, int third, int kind);

int func_800390B4(int value, Entry *entry) {
    int count = 0;

    while (1) {
        if (entry->third == 0) {
            break;
        }
        func_80039004(value++, entry->first, entry->second, 16, entry->third, 3);
        count++;
        entry++;
    }
    return count;
}
