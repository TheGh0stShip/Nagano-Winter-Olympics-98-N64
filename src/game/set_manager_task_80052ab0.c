typedef struct TaskRecord {
    unsigned short state;
    unsigned char pad_02[6];
    void *task;
    void *next;
} TaskRecord;

extern TaskRecord *D_8007DA94;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_80052AB0(void *task) {
    register unsigned int mask = func_8005BFD0();

    D_8007DA94->task = task;
    D_8007DA94->state = 1;
    D_8007DA94->next = ((void **)D_8007DA94->task)[1];
    func_8005BFF0(mask);
}
