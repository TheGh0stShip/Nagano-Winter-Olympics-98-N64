typedef struct PackedRecord {
    signed short first;
    signed short second;
    signed short third;
    signed short zero;
    signed short fourth;
    signed short fifth;
    unsigned char sixth;
    unsigned char seventh;
    unsigned char eighth;
    unsigned char ninth;
} PackedRecord;

void func_8001BDB8(PackedRecord *record, signed short first,
                   signed short second, signed short third,
                   signed short fourth, signed short fifth,
                   unsigned char sixth, unsigned char seventh,
                   unsigned char eighth, unsigned char ninth) {
    record->first = first;
    record->second = second;
    record->third = third;
    record->zero = 0;
    record->fourth = fourth;
    record->fifth = fifth;
    record->sixth = sixth;
    record->seventh = seventh;
    record->eighth = eighth;
    record->ninth = ninth;
}
