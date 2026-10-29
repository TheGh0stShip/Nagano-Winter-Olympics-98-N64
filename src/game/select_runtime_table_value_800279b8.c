typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;

typedef struct Runtime279B8 {
    unsigned char pad00[0x26];
    u16 flags;
} Runtime279B8;

extern unsigned char D_80136C9D;
extern s8 D_8007178E[2][3][30];
extern s8 D_8007186A[2][5][35];
extern s8 D_800719A2[2][3][30];

s8 func_800279B8(s16 index, Runtime279B8 *record, s8 subindex) {
    u16 flag;
    s8 result;

    flag = 0;
    if (record->flags & 1) {
        flag = 1;
    }
    switch (D_80136C9D) {
        case 0:
            result = D_8007178E[flag][index][subindex];
            break;
        case 1:
            result = D_8007186A[flag][index][subindex];
            break;
        case 2:
            result = D_800719A2[flag][index][subindex];
            break;
    }
    return result;
}
