typedef struct Course {
    unsigned char pad0[4];
    unsigned short mode;
    unsigned char pad6[0x2A];
    short phase;
} Course;

extern unsigned char *D_80126BF0;
extern short D_801376B4;

void func_80030AA0(unsigned char mode) {
    Course *course = (Course *)(D_80126BF0 + 0x92380);

    course->mode = mode;
    D_801376B4 = 0;
    switch (mode) {
        case 2:
        case 4:
            course->phase = 1;
            break;
        case 1:
        case 3:
            course->phase = 2;
            break;
        case 5:
        case 7:
            course->phase = 4;
            break;
        case 6:
        case 8:
            course->phase = 3;
            break;
        case 9:
            course->phase = 0;
            break;
        default:
            course->phase = 0;
            break;
    }
}
