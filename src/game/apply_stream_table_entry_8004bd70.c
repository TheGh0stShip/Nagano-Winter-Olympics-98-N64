typedef struct StreamState {
    unsigned char padding0[0x0D];
    signed char value;
    unsigned char padding1[0x17];
    unsigned char table_index;
} StreamState;

typedef struct StreamTableEntry {
    signed char value;
    unsigned char data[7];
} StreamTableEntry;

extern StreamState *D_80179924;
extern StreamTableEntry D_80073F90[];
extern void func_8004BC04(unsigned char *data);

void func_8004BD70(void) {
    StreamState *state = D_80179924;
    unsigned char *entry = (unsigned char *)&D_80073F90[state->table_index - 72];

    state->value = *(signed char *)entry;
    entry++;
    func_8004BC04(entry);
}
