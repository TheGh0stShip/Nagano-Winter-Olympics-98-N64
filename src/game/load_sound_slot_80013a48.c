typedef struct Sound { unsigned char pad[0x68]; } Sound;
extern unsigned char D_80130BE0[];
extern unsigned char D_80135930[];
extern Sound D_80135790[];
extern int func_8005CD50(void *bank, Sound *sound, int id);

int func_80013A48(unsigned char index) {
    int result = func_8005CD50(D_80130BE0, &D_80135790[index], index);

    if (result == 0) {
        D_80135930[index] = 0;
    } else {
        D_80135930[index] = 1;
    }
    return result;
}
