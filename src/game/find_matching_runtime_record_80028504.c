typedef unsigned char u8;

extern u8 D_801374B2;
extern u8 D_8006D470[][24][14];
extern u8 D_80137150[][9];

int func_80028504(u8 input) {
    int match;
    u8 record;
    u8 offset;

    for (record = 0; record < 16; record++) { match = 1;
        offset = 0; do { if (D_8006D470[D_801374B2][record][offset] == 0) {
                break;
            }
            if (D_80137150[input][offset] != D_8006D470[D_801374B2][record][offset]) {
                match = 0;
                break;
            }
            offset++;
        } while (offset < 9);
        if (match != 0) {
            return record;
        }
    }
    return 0;
}
