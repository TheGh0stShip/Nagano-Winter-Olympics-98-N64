typedef struct Track {
    unsigned char pad0[0x93];
    unsigned char first;
    unsigned char pad94;
    unsigned char scaled;
    unsigned char pad96[3];
    unsigned char mode;
    unsigned short length;
    unsigned char pad9C[2];
    unsigned char divisor;
    unsigned char pad9F;
    short step;
} Track;

extern unsigned char *D_80179920;
extern Track *D_80179924;

void func_8004C49C(void) {
    unsigned char value;
    unsigned char scaled;

    scaled = *D_80179920++;
    value = scaled;
    if (value < 100) {
        D_80179924->first = value;
    } else {
        D_80179924->first = 0;
        D_80179924->divisor = value - 100;
    }
    scaled = *D_80179920++;
    value = scaled;
    if (value < 0x40) {
        if (value < 0x20) {
            D_80179924->mode = 1;
            scaled <<= 3;
        } else {
            D_80179924->mode = 2;
            scaled <<= 2;
        }
    } else if (value < 0x80) {
        D_80179924->mode = 4;
        scaled <<= 1;
    } else if (value == 0xFF) {
        D_80179924->mode = 0x10;
    } else {
        D_80179924->mode = 8;
    }
    D_80179924->scaled = scaled;
    D_80179924->length = *D_80179920 << 8;
    D_80179920++;
    if (D_80179924->divisor != 0) {
        D_80179924->step = D_80179924->length / D_80179924->divisor;
    }
}
