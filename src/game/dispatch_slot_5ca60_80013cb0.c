typedef struct Sound {
    unsigned char pad[0x68];
} Sound;

extern unsigned char D_80135930[];
extern Sound D_80135790[];
extern void func_8005CA60(Sound *sound, int arg1, int arg2);
extern void func_80013F98(unsigned char index);

void func_80013CB0(unsigned char index, int arg1, int arg2) {
    if (D_80135930[index] == 0) {
        func_8005CA60(&D_80135790[index], arg1, arg2);
    } else {
        func_80013F98(index);
    }
}
