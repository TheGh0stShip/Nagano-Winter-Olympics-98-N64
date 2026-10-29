typedef struct Ctx
{
  int code;
  char pad4[0xA0];
  unsigned short hA4;
  char pad[0x10];
  unsigned char bB6;
  char padB7[9];
  short sC0;
} Ctx;
extern unsigned char *D_80179920;
extern Ctx *D_80179924;
extern unsigned short D_80179928;
extern void *D_8017992C;
extern unsigned short D_80179970;
extern unsigned short D_80179680[];
extern unsigned short D_80179684[];
extern unsigned short D_8017966A;
extern unsigned short D_8018CA24;
extern unsigned char D_80073B00[];
extern unsigned char D_80074678;
extern unsigned char D_8007467C;
extern char D_80074078[];
void func_8004D428(void)
{
  int first;
  int limit;
  int code;
  Ctx *s;
  int i;
  int j;
  int sum;
  unsigned char sel;
  unsigned short *p;
  first = *(D_80179920++);
  limit = (unsigned char) (0xFF - (*(D_80179920++)));
  code = D_80179924->code & 0x7FFF;
  switch (code)
  {
    case 281:
    case 314:
    case 333:
    case 334:
      if ((D_80179924->hA4 != 0) && (D_8018CA24 < 0xDC))
    {
      return;
    }
      if (D_80179924->sC0 < (-0xF))
    {
      return;
    }
      break;
    case 330:
      if ((D_80179924->hA4 != 0) && (D_8018CA24 < 0xDC))
    {
      return;
    }
      if (D_80179924->sC0 < (-6))
    {
      return;
    }
      break;
    case 290:
    case 293:
    case 294:
    case 295:
    case 296:
    case 297:
    case 300:
    case 304:
      if (D_80179924->bB6 != 0)
    {
      return;
    }
      for (i = 0; i < 2; i++)
    {
      if (code == D_80179680[i])
      {
        return;
      }
    }
      break;
    default:
      break;
  }
  D_80179970++;
  j = D_80179970 & 0x7F;
  D_80179928 = D_80073B00[j] << 8;
  j = (j + 1) & 0x7F;
  D_80179928 += D_80073B00[j];
  D_80179928 = (D_80179928 + (D_80179970 >> 7)) + (D_8017966A >> 1);
  if (((unsigned char) D_80179928) >= limit)
  {
    sel = (D_80179928 >> 8) & 7;
    if (((first | 0) == D_80074678) && (sel == D_8007467C))
    {
      sel = (++sel) & 7;
    }
    D_80074678 = first;
    D_8007467C = sel;
    D_8017992C = (D_80074078 + (first * 0x30)) + (sel * 6);
  }
  return;
}
