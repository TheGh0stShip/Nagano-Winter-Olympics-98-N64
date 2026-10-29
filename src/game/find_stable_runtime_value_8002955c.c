typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_80126BF0;
extern void func_8002B4B4(void);
extern float func_8002932C(float value);
extern float func_800293FC(float value, float offset);
extern float func_80028DE0(float value);

float func_8002955C(float value, float offset) {
    float current;
    float mapped;
    float transformed;
    float difference;
    u16 i;

    func_8002B4B4();
    if (D_80126BF0[0x977F4] != 0) {
        return value;
    }
    if (D_80126BF0[0x977F8] != 0) {
        return value;
    }
    if ((double)value < 20.0) {
        return value;
    }
    if (offset < 1.0f) {
        return value;
    }
    current = func_8002932C(value);
    for (i = 0; i < 10; i++) {
        mapped = func_800293FC(current, offset);
        transformed = func_80028DE0(mapped);
        if (mapped < transformed) {
            difference = mapped - transformed;
            difference = -difference;
        } else {
            difference = mapped - transformed;
        }
        if ((double)difference < 0.09) {
            break;
        }
        current = (double)current - 0.5;
    }
    return current;
}
