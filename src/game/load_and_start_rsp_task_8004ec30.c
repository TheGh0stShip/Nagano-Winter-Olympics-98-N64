typedef struct TaskData {
    unsigned int type;
    unsigned int flags;
    void *ucode_boot;
    unsigned int ucode_boot_size;
    void *ucode;
    unsigned int ucode_size;
    void *ucode_data;
    unsigned int ucode_data_size;
    void *dram_stack;
    unsigned int dram_stack_size;
    void *output_buff;
    void *output_buff_size;
    void *data_ptr;
    unsigned int data_size;
    void *yield_data_ptr;
    unsigned int yield_data_size;
} TaskData;

typedef union Task {
    TaskData t;
    long long force_structure_alignment;
} Task;

#define TO_PHYSICAL(ptr) if (ptr != 0) { ptr = (void *)func_800512C0(ptr); }

extern void func_8005BA20(void *src, void *dst, int size);
extern unsigned int func_800512C0(void *address);
extern void func_80051340(void *address, int size);
extern void func_8005F3D0(unsigned int status);
extern int func_8005FF80(unsigned int pc);
extern int func_80052120(int direction, unsigned int dest, void *src, unsigned int size);
extern int func_8005AB70(void);
extern Task D_80191990;

Task *func_8004EC30(Task *intp) {
    Task *tp;

    tp = &D_80191990;
    func_8005BA20(intp, tp, sizeof(Task));
    TO_PHYSICAL(tp->t.ucode);
    TO_PHYSICAL(tp->t.ucode_data);
    TO_PHYSICAL(tp->t.dram_stack);
    TO_PHYSICAL(tp->t.output_buff);
    TO_PHYSICAL(tp->t.output_buff_size);
    TO_PHYSICAL(tp->t.data_ptr);
    TO_PHYSICAL(tp->t.yield_data_ptr);
    return tp;
}

void func_8004ED4C(Task *intp) {
    Task *tp;

    tp = func_8004EC30(intp);
    if (tp->t.flags & 1) {
        tp->t.ucode_data = tp->t.yield_data_ptr;
        tp->t.ucode_data_size = tp->t.yield_data_size;
        intp->t.flags &= ~1;
        if (tp->t.flags & 4) {
            tp->t.ucode = (void *)*(unsigned int *)(((unsigned int)intp->t.yield_data_ptr + 0xC00 - 4) | 0xA0000000);
        }
    }
    func_80051340(tp, sizeof(Task));
    func_8005F3D0(0x2B00);
    while (func_8005FF80(0x04001000) == -1) {
    }
    while (func_80052120(1, 0x04001000 - sizeof(*tp), tp, sizeof(Task)) == -1) {
    }
    while (func_8005AB70()) {
    }
    while (func_80052120(1, 0x04001000, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1) {
    }
}

void func_8004EEDC(Task *tp) {
    while (func_8005AB70()) {
    }
    func_8005F3D0(0x125);
}
