extern unsigned char *D_80126BF0;
extern int D_80072704;
extern int D_80072708;
extern int D_8007270C;
extern int D_80072694[];

void func_8003EE70(unsigned char *input) {
    short i;

    if (input[0] >= 28) {
        *(unsigned short *)(D_80126BF0 + 0x848B8) = 0;
        *(int *)(D_80126BF0 + 0x849E4) = 0;
    } else if (input[2] >= 28) {
        *(unsigned short *)(D_80126BF0 + 0x848B8) = 1;
        if (input[2] == 30) {
            *(int *)(D_80126BF0 + 0x849E4) = D_80072704;
        } else {
            *(int *)(D_80126BF0 + 0x849E4) = D_80072708;
        }
    } else {
        *(unsigned short *)(D_80126BF0 + 0x848B8) = 1;
        *(int *)(D_80126BF0 + 0x849E4) = D_80072704;
    }
    for (i = 0; i < 4; i++) {
        if (input[i] == 25) {
            *(unsigned short *)(D_80126BF0 + i * 0x138 + 0x849F0) = 1;
            *(int *)(D_80126BF0 + i * 0x138 + 0x84B1C) = D_8007270C;
        } else if (input[i] < 28) {
            *(unsigned short *)(D_80126BF0 + i * 0x138 + 0x849F0) = 1;
            *(int *)(D_80126BF0 + i * 0x138 + 0x84B1C) = D_80072694[input[i]];
        } else {
            *(unsigned short *)(D_80126BF0 + i * 0x138 + 0x849F0) = 0;
        }
    }
}
