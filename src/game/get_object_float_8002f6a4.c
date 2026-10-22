typedef unsigned char u8;
extern char *func_8002A88C(void);
float func_8002F6A4(u8 index) {
    return *(float *)(func_8002A88C() + 0x190 + index * 4);
}
