typedef struct HandlerTable {
    void (*handlers[12])(void);
} HandlerTable;

extern unsigned char *D_80126BF0;
extern HandlerTable D_8006E5B4;

void func_80011C3C(void) {
    HandlerTable table = D_8006E5B4;

    table.handlers[D_80126BF0[0x977EC]]();
}
