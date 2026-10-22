typedef signed short s16;
typedef struct { int first, second, third; s16 fourth, fifth; int sixth; } Record;
void func_8005A3D0(Record *r, int second, int third, int sixth) { r->first = 0; r->second = second; r->third = third; r->fourth = 0; r->fifth = 0; r->sixth = sixth; }
