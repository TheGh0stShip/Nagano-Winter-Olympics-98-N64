typedef struct Course {
    short active;
    unsigned char pad2[2];
    short mode;
    unsigned char pad6[2];
    float value;
    unsigned char padC[0x24];
    short phase;
} Course;

typedef struct Block {
    int words[30];
} Block;

extern unsigned char *D_80126BF0;
extern Block D_80069158;
extern float D_801376B0;
extern short D_801376B4;
extern void func_8000A0DC(void);

void func_80030908(void) {
    Course *course;

    func_8000A0DC();
    course = (Course *)(D_80126BF0 + 0x92380);
    course->active = 1;
    course->mode = 9;
    course->phase = 0;
    course->value = 7.0f;
    *(Block *)(D_80126BF0 + 0x80230) = D_80069158;
    D_801376B0 = 255.0f;
    D_801376B4 = 0;
}
