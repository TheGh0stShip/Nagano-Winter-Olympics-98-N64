extern int D_80130C30[];
extern int func_80005E70(int id);

int func_80005EB8(unsigned char mode, int index, int id) {
    if (id == 0) {
        return 3;
    }
    if (func_80005E70(id) == 0) {
        return 1;
    }
    switch (mode) {
    case 0:
        if (D_80130C30[index] == id) {
            return 0;
        }
        break;
    case 1:
        if (D_80130C30[index] != 0) {
            return 0;
        }
        break;
    }
    D_80130C30[index] = id;
    return 2;
}
