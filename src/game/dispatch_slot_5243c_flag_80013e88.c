typedef struct Sound {
    unsigned char pad[0x68];
} Sound;

extern unsigned char D_80135930[];
extern Sound D_80135790[];
extern void func_8005243C(Sound *sound, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void func_80013F98(unsigned char index);

void func_80013E88(unsigned char index, int arg1, int arg2, int arg3, int arg4) {
    if (D_80135930[index] == 0) {
        func_8005243C(&D_80135790[index], arg1, 1, arg2, arg3, arg4);
    } else {
        func_80013F98(index);
    }
}
