extern unsigned char *D_80126BF0;
extern unsigned char D_801374B2;
extern float D_801374B4;
extern unsigned char D_801374C9;
extern signed char D_80071A50[];
extern signed char D_80071A5C[];
extern unsigned char D_80137260[][7];
extern int func_8002B4B4(void);

void func_8002A0F8(float value)
{
    float result;
    float cur;
    int n;
    unsigned char idx;
    unsigned char r;

    if (D_801374B2 == 11)
    {
        n = func_8002B4B4();
        idx = D_80126BF0[0x977EC];
        r = D_80137260[n][D_80071A5C[idx]];
        if (r == 0)
        {
            cur = D_80071A50[idx] * D_801374B4;
            result = D_80071A50[idx] * value;
            if (result < cur)
            {
                D_801374B4 = value;
                D_801374C9 = 1;
            }
        }
    }
}
