extern double D_8007FB70;
extern double D_8007FB78;
extern double D_8007FB80;
extern double D_8007FB88;
extern double D_8007FB90;

#define ABSDIFF(a, b, d) ((a) < (b) ? -(d) : (d))

float func_80022F44(float a, float b, unsigned char type) {
    float diff;
    float result;

    if (a > 360.0f) a -= 360.0f;
    if (a < -360.0f) a += 360.0f;
    if (b > 360.0f) b -= 360.0f;
    if (b < -360.0f) b += 360.0f;
    diff = a - b;
    if (diff < -180.0f) {
        result = 360.0f - ABSDIFF(a, b, diff);
    } else if (a < b) {
        result = ABSDIFF(a, b, diff) * -1.0f;
    } else if (diff < 180.0f) {
        result = ABSDIFF(a, b, diff);
    } else {
        result = (360.0f - ABSDIFF(a, b, diff)) * -1.0f;
    }
    switch (type) {
    default:
        result = result * D_8007FB70;
        break;
    case 1:
        result = result * D_8007FB78;
        break;
    case 8:
        result = result * D_8007FB80;
        break;
    case 2:
        result = result * D_8007FB88;
        break;
    case 0xF0:
        result = result * D_8007FB90;
        break;
    }
    return result;
}
