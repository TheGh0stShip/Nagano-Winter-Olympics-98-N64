extern unsigned char *func_8002A88C(void);
extern unsigned short D_80071E40[];
extern void func_80048580(unsigned short);

void func_8002E8C4(unsigned char index) {
    unsigned char *objects = func_8002A88C();

    if (*(unsigned char *)((unsigned int)objects + index + 0x180) != 0) {
        func_80048580(D_80071E40[index]);
    }
}
