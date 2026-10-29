extern char D_8006F81C[];
extern char D_8006F894[];
extern char D_8006F8BC[];
extern char D_8006F8E4[];
extern char D_80072B04[];
extern char D_060204A8[];
extern char D_06020548[];
extern char D_060206D8[];
extern char D_06020A18[];
extern int func_8001D7D8(char *);
extern void func_80006D84(unsigned short, char *);
extern void func_8001DB48(char *, float, float, int);
extern void func_8001E054(int, float, float, int, char *, int);
extern void func_8001E238(int, int, int, char *);

int func_8001D808(char **lines, float scroll) {
    int k = 0;
    float y = -((int)scroll % 16);
    int row = scroll * 0.0625f;
    int cnt;
    int w;
    int step = 16;
    int limit = 272;
    int c;

    for (cnt = 0; ; cnt++) {
        if (row >= 0) {
            if ('%' == *lines[row]) {
                break;
            }
            if (*lines[row] != 0) {
                switch (*lines[row]) {
                case '^':
                    func_8001E054(k, 0.0f, 120 - (int)y, 0x11, D_06020548, 1);
                    func_8001E238(k, 0xC0, 0x30, D_8006F8BC);
                    k++;
                    break;
                case '!':
                    func_8001E054(k, 0.0f, 120 - (int)y, 0x11, D_060204A8, 1);
                    func_8001E238(k, 0xC0, 0x30, D_8006F8E4);
                    k++;
                    break;
                case '#':
                    func_8001E054(k, 0.0f, 120 - (int)y, 0x11, D_060206D8, 1);
                    func_8001E238(k, 0xC0, 0x30, D_8006F81C);
                    k++;
                    break;
                case '$':
                    func_8001E054(k, 0.0f, 120 - (int)y, 0x11, D_06020A18, 1);
                    func_8001E238(k, 0xC0, 0x30, D_8006F894);
                    k++;
                    break;
                default:
                    if (*lines[row] != 0) {
                        w = -(func_8001D7D8(lines[row]) * 8) / 2 - 16;
                        func_80006D84(k, D_80072B04);
                        func_8001DB48(lines[row], w, 120 - (int)y, k);
                        k++;
                    }
                    break;
                }
            }
        }
        row++;
        y += step;
        if (limit < y) {
            break;
        }
    }
    return cnt;
}
