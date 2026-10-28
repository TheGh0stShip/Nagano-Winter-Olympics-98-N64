typedef struct Course {
    unsigned char pad0[4];
    unsigned short mode;
    unsigned char pad6[2];
    float value;
    unsigned char padC[0x24];
    short phase;
    unsigned char pad32[3];
    unsigned char flag;
} Course;

extern unsigned char *D_80126BF0;
extern float D_801376B0;
extern short D_801376B4;

void func_80030D28(unsigned char mode, float value) {
    Course *course = (Course *)(D_80126BF0 + 0x92380);

    course->flag = 0;
    course->mode = mode;
    course->value = value;
    D_801376B0 = 255.0f;
    D_801376B4 = 0;
    if (mode == 1 || mode == 3) {
        course->phase = 2;
    } else {
        course->phase = 0;
    }
}
