typedef struct Cfg
{
  int a;
  unsigned int rate;
  int c;
} Cfg;
typedef struct Syn
{
  unsigned char pad0[0x10];
  void *drv;
  int heap;
  int ratio;
} Syn;
typedef struct Pair
{
  void *a;
  void *b;
} Pair;
typedef struct Buf
{
  void *data;
  unsigned char pad[0x6C];
  short kind;
  short pad72;
  void *self;
} Buf;
typedef struct Slot3
{
  void *x;
  void *y;
  Buf *buf;
} Slot3;
extern unsigned char D_80047A78[];
extern unsigned char D_80047F28[];
typedef struct AM { void *acmd[2]; Buf *info[3]; } AM;
extern AM D_801386C0;
extern unsigned char D_801386CC[];
extern unsigned char D_801386D8[];
extern unsigned char D_80138888[];
extern unsigned char D_801388A0[];
extern unsigned char D_801389A0[];
extern unsigned char D_801389B8[];
extern unsigned char D_80138AB8[];
extern unsigned char D_8013CB08[];
typedef struct Hd
{
  int a;
  int b;
} Hd;
typedef struct DmaB { Hd node; int start; unsigned int last; void *ptr; } DmaB;
extern DmaB D_8013CB18[];
extern unsigned char D_8013CB2C[];
extern unsigned int D_8013CF00;
extern unsigned int D_8013CF04;
extern unsigned int D_8013CF08;
extern int D_8013CF0C;
extern unsigned char D_8013D510[];
extern unsigned char D_8013D528[];
extern void func_8004E750(void *, void *);
extern void func_8004E7AC(void *, Syn *);
extern void func_80050A90(void *, int, void *, int, void *, int);
extern void func_8005A5D0(void *, void *, int);
extern int func_8005B820(int);
extern void *func_8005F420(int, int, int, int, int);
extern void func_8005F810(void *);
void func_80047770(Syn *syn, int arg1, Cfg *cfg)
{
  unsigned int j;
  float f;
  unsigned char *q;
  unsigned char *p;
  void **pp;
  Buf **bp;
  syn->drv = D_80047F28;
  syn->ratio = func_8005B820(cfg->a);
  j = 0x10;
  do
  {
    j--;
  }
  while (j != 0);
  f = (((float) cfg->rate) * ((float) syn->ratio)) / 60.0f;
  D_8013CF04 = (int) f;
  if (((float) D_8013CF04) < f)
  {
    D_8013CF04++;
  }
  if (D_8013CF04 & 0xF)
  {
    D_8013CF04 = (D_8013CF04 & (~0xF)) + 0x10;
  }
  D_8013CF00 = D_8013CF04 - 0x10;
  D_8013CF08 = D_8013CF04 + 0xB0;
  func_8004E7AC(D_80138AB8, syn);
  D_8013CB18[0].node.b = 0;
  D_8013CB18[0].node.a = 0;
  for (j = 0; j < 0x31; j++)
  {
    func_8004E750(&D_8013CB18[j + 1], &D_8013CB18[j]);
    D_8013CB18[j].ptr = func_8005F420(0, 0, syn->heap, 1, 0xA00);
  }
  D_8013CB18[j].ptr = func_8005F420(0, 0, syn->heap, 1, 0xA00);
  for (j = 0; j < 2; j++)
  {
    D_801386C0.acmd[j] = func_8005F420(0, 0, syn->heap, 1, cfg->c * 8);
  }
  D_8013CF0C = cfg->c;
  for (j = 0; j < 3; j++)
  {
    D_801386C0.info[j] = func_8005F420(0, 0, syn->heap, 1, 0x90);
    D_801386C0.info[j]->kind = 2;
    D_801386C0.info[j]->self = D_801386C0.info[j];
    D_801386C0.info[j]->data = func_8005F420(0, 0, syn->heap, 1, 4 * D_8013CF08);
  }
  func_8005A5D0(D_801389A0, D_801389B8, 0x40);
  func_8005A5D0(D_80138888, D_801388A0, 0x40);
  func_8005A5D0(D_8013D510, D_8013D528, 0x40);
  func_80050A90(D_801386D8, 3, D_80047A78, 0, D_8013CB08, arg1);
  func_8005F810(D_801386D8);
}
