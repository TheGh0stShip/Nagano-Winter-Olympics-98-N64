extern unsigned char *D_80126BF0;
extern unsigned short D_80135722;
extern unsigned short D_80135724;
extern signed char D_80135726;
extern unsigned short D_80135728;
extern unsigned short D_8013572A;

void func_800163B8(void) {
    unsigned short dirs = 0;

    if (*(short *)(D_80126BF0 + 0x78000 + 0x48FA) < -40) {
        dirs = 0x200;
    }
    if (*(short *)(D_80126BF0 + 0x78000 + 0x48FA) > 40) {
        dirs |= 0x100;
    }
    if (*(short *)(D_80126BF0 + 0x78000 + 0x48FC) > 40) {
        dirs |= 0x800;
    }
    if (*(short *)(D_80126BF0 + 0x78000 + 0x48FC) < -40) {
        dirs |= 0x400;
    }
    D_80135724 = (D_80135722 ^ dirs) & dirs;
    D_80135722 = dirs;
    if (((*(unsigned short *)(D_80126BF0 + 0x78000 + 0x48F8) | D_80135724) & 0xF00) || (*(unsigned short *)(D_80126BF0 + 0x78000 + 0x48F8) & 0xC000)) {
        D_80135728 = D_8013572A = (*(unsigned short *)(D_80126BF0 + 0x78000 + 0x48F8) | D_80135724) & 0xF00;
        D_80135726 = 18;
    } else {
        D_80135728 = 0;
    }
    if (D_80135726 == 0) {
        D_80135728 = (*(unsigned short *)(D_80126BF0 + 0x78000 + 0x48F6) | D_80135722) & D_8013572A;
        D_80135726 = 6;
    } else {
        D_80135726--;
    }
}
