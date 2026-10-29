extern void func_8005DB40(unsigned int devAddr, unsigned int data);
extern int func_800504B0(unsigned int devAddr, unsigned int *data);
extern void func_80051340(void *address, int size);
extern void func_800015C4(unsigned int devAddr, void *vAddr, int size);
extern void func_800596D0(void);
extern void func_800596EC(void);
extern void func_80059D80(void *(*callback)(void *, const unsigned char *, int), int arg, int format, void *args);
extern unsigned char D_801AA600[0x200];

void *func_8000187C(void *arg, const unsigned char *src, int count);

void func_80001650(void) {
    if (*(volatile unsigned int *)0xBFF00000 != 0x4B4D4300) {
        func_8005DB40(0xB1FF0014, 0);
        func_8005DB40(0xB1FF0004, 0);
        func_8005DB40(0xB1FF0000, 0x49533634);
    }
}

void func_80001768(unsigned int *command, unsigned int value);
void func_800017FC(int arg0, ...);
void func_8000183C(int arg0, ...);

void func_800016AC(void) {
    unsigned short i;

    if (*(unsigned int *)0xBFF00000 != 0x4B4D4300) {
        func_800015C4(0, D_801AA600, 0x100);
        func_800015C4(0x01000000, D_801AA600 + 0x100, 0x100);
        for (i = 0; i < 0x100; i++) {
            if (D_801AA600[i] != D_801AA600[i + 0x100]) {
                func_80001768((unsigned int *)func_800596EC, (unsigned int)func_800017FC);
                func_80001768((unsigned int *)func_800596D0, (unsigned int)func_8000183C);
                return;
            }
        }
    }
}

void func_80001768(unsigned int *command, unsigned int value) {
    command[0] = 0x3C190000 + ((value >> 16) & 0xFFFF);
    command[1] = 0x27390000 + (value & 0xFFFF);
    command[2] = 0x03200008;
    command[3] = 0;
    func_80051340(command, 16);
}

void func_800017BC(int arg0, ...) {
    func_80059D80(func_8000187C, 0, arg0, (char *)&arg0 + 4);
}

void func_800017FC(int arg0, ...) {
    func_80059D80(func_8000187C, 0, arg0, (char *)&arg0 + 4);
}

void func_8000183C(int arg0, ...) {
    func_80059D80(func_8000187C, 0, arg0, (char *)&arg0 + 4);
}

void *func_8000187C(void *arg, const unsigned char *src, int count) {
    unsigned int data;
    int readPos;
    int writePos;
    int pos;
    int end;
    unsigned int addr;
    int shift;

    func_800504B0(0xB1FF0000, &data);
    if (data != 0x49533634) {
        return (void *)1;
    }
    func_800504B0(0xB1FF0004, &data);
    readPos = data;
    func_800504B0(0xB1FF0014, &data);
    writePos = data;
    end = writePos + count;
    pos = writePos;
    if (end >= 0xFFE0) {
        end -= 0xFFE0;
        if (readPos < end || writePos < readPos) {
            return (void *)1;
        }
    } else if (writePos < readPos && readPos < end) {
        return (void *)1;
    }
    while (count != 0) {
        addr = (pos & 0x0FFFFFFC) + 0xB1FF0020;
        if (*src != 0) {
            func_800504B0(addr, &data);
            shift = (3 - (pos & 3)) * 8;
            func_8005DB40(addr, (*src << shift) | (data & ~(0xFF << shift)));
            pos++;
            if (pos >= 0xFFE0) {
                pos -= 0xFFE0;
            }
        }
        count--;
        src++;
    }
    func_8005DB40(0xB1FF0014, pos);
    return (void *)1;
}
