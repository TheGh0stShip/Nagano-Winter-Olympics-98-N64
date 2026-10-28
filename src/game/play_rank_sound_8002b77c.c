extern void func_8002B81C(int id, unsigned char value);
extern void func_8002B84C(int id, int value);
extern void func_80048A78(unsigned short sound);
void func_8002B77C(unsigned char value, unsigned char rank, unsigned char first, unsigned char second, int score) {
    if ((int)rank) {
        func_8002B81C(0x446, value);
        func_8002B84C(0, score);
        if (first) {
            func_80048A78((int)rank + 0x461);
        } else if (second) {
            func_80048A78(0x466);
        } else {
            func_80048A78(0x461);
        }
    } else {
        func_80048A78(0x467);
    }
}
