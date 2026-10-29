typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_80126BF0;
extern u8 D_8008F3C8;
extern u8 *D_801330B0;
extern u8 *D_801330B4;
extern int D_801330B8;
extern int D_801330BC;
extern int D_801330C0;
extern u16 D_801330C4;
extern u16 D_801330C6;
extern void func_800015C4(unsigned int devAddr, void *vAddr, int size);

u8 *func_8000C014(u8 *data);
void func_8000C098();

u8 *func_8000B9C0(u8 *src, u8 *dst) {
    u8 *end = src + *(int *)src;
    u8 c;
    u16 n;
    u8 *p;
    u8 val;
    u16 off;

    src += 4;
    while (src < end) {
        c = *src++;
        if (c < 0x80) {
            off = (*src++ + (c << 8)) & 0x3FF;
            n = (c >> 2) + 2;
            p = dst - off;
            while (n--) {
                *dst++ = *p++;
            }
            continue;
        } else if (c < 0xA0) {
            n = c & 0x1F;
            while (n--) {
                *dst++ = *src++;
            }
            continue;
        } else if (c < 0xE0) {
            n = (c & 0x1F) + 2;
            val = *src++;
        } else if (c < 0xFF) {
            val = 0;
            n = (c & 0x1F) + 2;
        } else {
            val = 0;
            n = *src++ + 2;
        }
        while (n--) {
            *dst++ = val;
        }
    }
    return dst;
}

u8 *func_8000BB14(u8 *rom, u8 *dst, int size) {
    int pad[3];
    u8 *src;
    u8 *end;
    u8 *base;
    unsigned int len;
    u8 c;
    u16 n;
    u16 off;
    u8 *p;
    u8 val;

    D_801330B0 = D_801330B4 = rom;
    D_801330B8 = D_801330BC = size;
    D_801330BC--;
    src = D_80126BF0 + 0x967E0;
    func_8000C098(rom);
    while (D_801330BC > 0) {
        len = *src << 24;
        src = func_8000C014(src);
        len += *src << 16;
        src = func_8000C014(src);
        len += *src << 8;
        src = func_8000C014(src);
        len += *src;
        src = func_8000C014(src);
        end = D_801330B4 + len - 4;
        if (!(len & 0xF0000000)) {
            while (D_801330B4 < end) {
                c = *src;
                src = func_8000C014(src);
                if (c < 0x80) {
                    off = (*src + (c << 8)) & 0x3FF;
                    n = (c >> 2) + 2;
                    src = func_8000C014(src);
                    p = dst - off;
                    while (n--) {
                        *dst++ = *p++;
                    }
                    continue;
                } else if (c < 0xA0) {
                    n = c & 0x1F;
                    while (n--) {
                        *dst++ = *src;
                        src = func_8000C014(src);
                    }
                    continue;
                } else if (c < 0xE0) {
                    n = (c & 0x1F) + 2;
                    val = *src;
                    src = func_8000C014(src);
                } else if (c < 0xFF) {
                    val = 0;
                    n = (c & 0x1F) + 2;
                } else {
                    val = 0;
                    n = *src + 2;
                    src = func_8000C014(src);
                }
                while (n--) {
                    *dst++ = val;
                }
            }
        } else {
            D_801330C4 = 0;
            D_801330C6 = (u16)((len & 0xF0000000) >> 28) + 1;
            base = dst;
            while (D_801330C4 < D_801330C6) {
                if (D_801330C4 != 0) {
                    len = *src << 24;
                    src = func_8000C014(src);
                    len += *src << 16;
                    src = func_8000C014(src);
                    len += *src << 8;
                    src = func_8000C014(src);
                    len += *src;
                    src = func_8000C014(src);
                    end = D_801330B4 + len - 4;
                    dst = base;
                }
                len &= 0x0FFFFFFF;
                while (D_801330B4 < end) {
                    c = *src;
                    src = func_8000C014(src);
                    if (c < 0x80) {
                        off = (*src + (c << 8)) & 0x3FF;
                        src = func_8000C014(src);
                        n = (c >> 2) + 2;
                        p = dst - off * D_801330C6;
                        while (n--) {
                            *dst = *p;
                            dst += D_801330C6;
                            p += D_801330C6;
                        }
                        continue;
                    } else if (c < 0xA0) {
                        n = c & 0x1F;
                        while (n--) {
                            *dst = *src;
                            dst += D_801330C6;
                            src = func_8000C014(src);
                        }
                        continue;
                    } else if (c < 0xE0) {
                        n = (c & 0x1F) + 2;
                        val = *src;
                        src = func_8000C014(src);
                    } else if (c < 0xFF) {
                        val = 0;
                        n = (c & 0x1F) + 2;
                    } else {
                        val = 0;
                        n = *src + 2;
                        src = func_8000C014(src);
                    }
                    while (n--) {
                        *dst = val;
                        dst += D_801330C6;
                    }
                }
                base++;
                D_801330C4++;
            }
        }
    }
    return dst;
}

u8 *func_8000C014(u8 *data) {
    D_801330B4++;
    D_801330C0--;
    D_801330BC--;
    if (D_801330C0 != 0) {
        data++;
    } else {
        data = D_80126BF0 + 0x967E0;
        func_8000C098(data);
    }
    return data;
}

void func_8000C098(void) {
    D_801330C0 = 0x1000;
    D_801330B8 -= D_801330C0;
    if (D_801330B8 < 0) {
        D_801330C0 += (D_801330B8 + 1) & ~1;
        D_801330B8 = 0;
    }
    if (D_801330C0 > 0) {
        D_8008F3C8 = 1;
        func_800015C4((unsigned int)D_801330B0, D_80126BF0 + 0x967E0, D_801330C0);
        D_8008F3C8 = 0;
    }
    D_801330B0 += D_801330C0;
}
