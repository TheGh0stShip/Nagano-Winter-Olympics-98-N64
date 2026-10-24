extern void func_80051340(unsigned char *, int);

void func_8002F724(int first, int second, int third,
                   unsigned char *record) {
    record[0] = first;
    record[1] = second;
    record[2] = third;
    record[4] = first;
    record[5] = second;
    record[6] = third;
    func_80051340(record, 8);
}
