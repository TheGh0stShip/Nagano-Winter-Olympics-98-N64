extern void func_8000EC50(unsigned char *);

void func_80041194(unsigned char *out) {
    unsigned char buf[0x112];
    short i;
    short j;

    func_8000EC50(buf);
    out[0] = buf[0];
    if (out[0] != 0) {
        out[1] = buf[1];
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 7; j++) {
                out[i * 7 + j + 2] = buf[i * 9 + j + 2] + ((buf[i * 9 + 9] & (1 << j)) << (7 - j));
            }
        }
        for (i = 0; i < 8; i++) {
            out[i + 0x72] = 0;
        }
        for (i = 0; i < 16; i++) {
            (out + 0x72)[i / 2] |= (buf[i + 0x92] & 0xF) << (i % 2 * 4);
        }
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 6; j++) {
                out[i * 6 + j + 0x7A] = buf[i * 7 + j + 0xA2];
            }
        }
    }
}
