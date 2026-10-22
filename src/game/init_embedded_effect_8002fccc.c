extern void func_8002FC74(void *, int, int, int);

void func_8002FCCC(void *object, int red, int green, int blue) {
    func_8002FC74((unsigned char *)object + 0x38, red, green, blue);
}
