typedef struct Sound {
    unsigned char pad[0x68];
} Sound;

typedef struct Request {
    unsigned char pad0[4];
    int data;
    unsigned short length;
    unsigned char first[4];
    unsigned char second[4];
} Request;

extern unsigned char D_80135930[];
extern Sound D_80135790[];
extern void func_80053470(Sound *sound, unsigned short length, int data, unsigned char *second, unsigned char *first, int arg5, int arg6);
extern void func_80013F98(unsigned char index);

void func_80013B0C(unsigned char index, Request *request, int arg2, int arg3) {
    if (D_80135930[index] == 0) {
        func_80053470(&D_80135790[index], request->length, request->data, request->second, request->first, arg2, arg3);
    } else {
        func_80013F98(index);
    }
}
