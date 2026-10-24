extern void func_8002F7BC(unsigned int fourth, unsigned int fifth,
                          unsigned int sixth, void *record);
extern void func_8002F774(unsigned int first, unsigned int second,
                          unsigned int third, void *record);
extern void func_80051340(void *record, unsigned int size);

void func_8002F900(unsigned int first, unsigned int second,
                   unsigned int third, unsigned int fourth,
                   unsigned int fifth, unsigned int sixth, void *record) {
    func_8002F7BC(fourth, fifth, sixth, record);
    func_8002F774(first, second, third, record);
    func_80051340(record, 0x10);
}
