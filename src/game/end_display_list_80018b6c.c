typedef struct DisplayListOwner {
    unsigned char pad[0x12C];
    struct DisplayCommand *end;
} DisplayListOwner;

typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

extern DisplayCommand *D_80126BF4;

void func_80018B6C(DisplayListOwner *owner, int unused) {
    DisplayCommand *command;
    owner->end = D_80126BF4;
    command = D_80126BF4++;
    command->argument = 0;
    command->opcode = 0xB8000000;
}
