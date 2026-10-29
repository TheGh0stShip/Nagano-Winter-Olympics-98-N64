typedef struct PortEntry {
    signed char id;
    signed char pad;
} PortEntry;

extern PortEntry D_80138220[];
extern void func_80040668(unsigned char *flags);

void func_8003FA38(unsigned char port, unsigned char *out) {
    unsigned char flags;
    short i;
    int found;

    *out = 1 << port;
    func_80040668(&flags);
    found = 0;
    if (port > 0) {
        for (i = 0; i < port; i++) {
            if (flags & (1 << i)) {
                found = 1;
                break;
            }
        }
    }
    if (found == 0) {
        for (i = port; i < 4; i++) {
            if ((flags & (1 << i)) && D_80138220[i].id != D_80138220[port].id) {
                *out |= 1 << i;
            }
        }
    }
    found = 0;
    if (port > 0) {
        for (i = 0; i < port; i++) {
            if (D_80138220[i].id == D_80138220[port].id) {
                found = 1;
                break;
            }
        }
    }
    if (found == 0) {
        for (i = port; i < 4; i++) {
            if (D_80138220[i].id == D_80138220[port].id && (flags & (1 << i)) == 0) {
                *out |= 1 << i;
            }
        }
    }
}
