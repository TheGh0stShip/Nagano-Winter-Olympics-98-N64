extern int func_80029200(float value);
extern float func_80029728(void);

float func_80029198(float value) {
    long long unused;
    unsigned short i;
    float start;

    start = value; for (i = 0; i < 101; i++) {
        if (!func_80029200(value)) {
            return value;
        }
        value += func_80029728();
    }
    return start;
}
