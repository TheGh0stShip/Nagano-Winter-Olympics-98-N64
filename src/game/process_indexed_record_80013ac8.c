typedef unsigned char u8;

typedef struct RuntimeRecord {
    u8 bytes[104];
} RuntimeRecord;

extern RuntimeRecord D_80135790[];
extern void func_8005A890(RuntimeRecord *record);

void func_80013AC8(u8 index) {
    func_8005A890(&D_80135790[index]);
}
