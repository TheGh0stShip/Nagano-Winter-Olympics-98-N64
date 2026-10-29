typedef struct 
{
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int i;
} S24;
typedef union { long long ll; int w[2]; } U8;
extern S24 D_80133588;
U8 D_80133590;
U8 D_80133598;
extern int D_80133594;
extern int func_80005E18(int, int);
void func_8000D034(S24 *arg0)
{
  int pad[2];
  int c;
  int d;
  int e;
  int f;
  D_80133588 = *arg0;
  c = func_80005E18(0xE, D_80133588.c);
  d = func_80005E18(0xE, D_80133590.w[1]);
  e = func_80005E18(0xE, D_80133598.w[0]);
  f = func_80005E18(0xE, D_80133590.w[3]);
  if (1) { D_80133590.w[0] = c; D_80133590.w[1] = d; }
  if (1) { D_80133598.w[0] = e; D_80133598.w[1] = f; }
}
