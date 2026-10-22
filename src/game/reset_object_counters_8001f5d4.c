typedef struct RuntimeObject {
    unsigned char pad[0x19C];
    unsigned short first;
    unsigned short second;
} RuntimeObject;

extern unsigned char *D_80126BF0;
extern void func_80003C10(void *, int);

void func_8001F5D4(RuntimeObject *object) {
    func_80003C10(D_80126BF0 + 0x92C78, 15000);
    object->first = 0;
    object->second = 0;
}
