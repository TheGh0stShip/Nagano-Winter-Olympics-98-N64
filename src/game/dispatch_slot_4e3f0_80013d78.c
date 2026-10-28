typedef struct Sound {
    unsigned char pad[0x68];
} Sound;

extern unsigned char D_80135930[];
extern Sound D_80135790[];
extern void func_8004E3F0(Sound *sound, int arg1);
extern void func_80013F98(unsigned char index);

void func_80013D78(unsigned char index, int arg1) {
    if (D_80135930[index] == 0) {
        func_8004E3F0(&D_80135790[index], arg1);
    } else {
        func_80013F98(index);
    }
}
