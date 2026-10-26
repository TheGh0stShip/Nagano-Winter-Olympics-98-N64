typedef struct RuntimeCodeRecord {
    unsigned char pad[0xD0];
} RuntimeCodeRecord;

extern unsigned int D_8018C980[];

int func_8004A560(int index) {
    unsigned int code =
        *(unsigned int *)((unsigned char *)D_8018C980 +
                         index * sizeof(RuntimeCodeRecord)) & 0x7FFF;

    if (code == 0x2CE || code == 0x2CF || code == 0x2D0 ||
        code == 0x3EC || code == 0x4AC) {
        return 0;
    }
    return 1;
}
