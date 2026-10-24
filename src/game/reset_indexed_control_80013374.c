typedef struct ControlRecord {
    unsigned short value;
    unsigned char unused;
    unsigned char index;
    unsigned char pad4[0x38];
} ControlRecord;

extern unsigned short D_80135228[];

extern void func_80013128(unsigned short, ControlRecord *, int, int);
extern void func_800130B0(ControlRecord *);
extern void func_80013108(ControlRecord *);

void func_80013374(unsigned short index) {
    ControlRecord record;

    func_80013128(index, &record, 0, 0);
    D_80135228[index] = 0;
    record.index = index;
    func_800130B0(&record);
    func_80013108(&record);
}
