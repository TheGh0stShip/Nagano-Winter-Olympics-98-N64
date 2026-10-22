extern char D_8000187C[];
extern void func_80059D80(char *, int, int, void *);

void func_800017FC(int arg0, ...) {
    func_80059D80(D_8000187C, 0, arg0, (char *)&arg0 + 4);
}
