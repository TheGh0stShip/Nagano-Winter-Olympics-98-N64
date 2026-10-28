typedef struct Course {
    unsigned char pad[8];
    float width;
} Course;

extern unsigned char *D_80126BF0;
extern void func_800309B4(signed char first, signed char second);

void func_80030A38(signed char first, signed char second) {
    Course *course = (Course *)(D_80126BF0 + 0x92380);

    course->width = second / 2;
    func_800309B4(first, second);
}
