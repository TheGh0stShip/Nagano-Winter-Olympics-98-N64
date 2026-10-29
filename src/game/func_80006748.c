typedef struct Entry
{
  unsigned int id;
  int value;
} Entry;
extern Entry D_80063768;
extern Entry D_80063770;
extern Entry D_800639A8[][13];
extern Entry D_80063798;
extern Entry D_80064028[][13];
extern Entry D_800637A8;
extern Entry D_800646A8[][13];
extern Entry D_800637F8;
extern Entry D_80064D28[][13];
extern Entry D_800637B8;
extern Entry D_800653A8[][13];
extern Entry D_80063870;
extern Entry D_80065A28[][13];
extern Entry D_80063888;
extern Entry D_800660A8[][13];
extern Entry D_800638A8;
extern Entry D_80066728[][13];
extern Entry D_800638B8;
extern Entry D_80066DA8[][13];
extern Entry D_800638D8;
extern Entry D_80067428[][13];
extern unsigned char D_80067AA8[];
extern signed char D_8006C340;
extern Entry D_80131540[];
extern void func_800060B4(unsigned char *, unsigned int, Entry *);
extern int func_80005FA4(unsigned int, Entry *);
void func_80006748(unsigned char mode, unsigned char item)
{
  unsigned char flag;
  unsigned char row;
  Entry *entry;
  short i;
  unsigned int id;
  Entry *p;
  Entry *ptrs[2];
  flag = 1;
  row = D_80067AA8[item];
  for (i = 0; i < 2; i++)
  {
    ptrs[i] = 0;
  }

  switch (mode)
  {
    case 0:

    case 1:
      ptrs[0] = &D_80063768;
      ptrs[1] = &D_80063770;
      entry = D_800639A8[row];
      break;

    case 2:

    case 3:
      ptrs[0] = &D_80063798;
      entry = D_80064028[row];
      break;

    case 4:
      ptrs[0] = &D_800637A8;
      entry = D_800646A8[row];
      break;

    case 5:
      ptrs[0] = &D_800637F8;
      entry = D_80064D28[row];
      break;

    case 6:
      ptrs[0] = &D_800637B8;
      entry = D_800653A8[row];
      break;

    case 7:

    case 8:
      ptrs[0] = &D_80063870;
      entry = D_80065A28[row];
      break;

    case 9:
      ptrs[0] = &D_80063888;
      entry = D_800660A8[row];
      break;

    case 10:
      ptrs[0] = &D_800638A8;
      entry = D_80066728[row];
      break;

    case 11:
      ptrs[0] = &D_800638B8;
      entry = D_80066DA8[row];
      break;

    case 12:
      ptrs[0] = &D_800638D8;
      entry = D_80067428[row];
      break;

    default:
      return;

  }

  for (i = 0; i < 2; i++)
  {
    p = ptrs[i];
    if (ptrs[i] == 0)
    {
      break;
    }
    func_800060B4(&flag, p->id & 0x0FFFFFFF, p);
  }

  while (0 != (id = entry->id))
  {
    id = func_80005FA4(id & 0x0FFFFFFF, entry);
    if (id != 0)
    {
      if ((id ^ 0) == 2)
      {
        D_80131540[D_8006C340] = *entry;
        D_8006C340++;
        if (id) {}
      }
    }
    if ((id == 2) | (id == 3)) {}
    entry++;
  }
  if (id == 2) {}


}

