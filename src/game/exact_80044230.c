typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

typedef struct Source {
    float x;
    float y;
    unsigned char pad8[4];
    unsigned char type;
} Source;

typedef struct Slot {
    unsigned char pad0[0x21];
    unsigned char next;
    unsigned char pad22[0x10];
    unsigned short alpha;
} Slot;

typedef struct Record {
    unsigned short kind;
    unsigned char pad2[0xA];
    float f0C;
    float f10;
    float f14;
    unsigned char pad18[0x10];
    float scale;
    unsigned char pad2C[0x100];
    DisplayCommand *list;
} Record;

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern float D_80080C68;
extern void func_80018F20(unsigned char kind, unsigned short alpha, float x, float y, float z);

void func_80044230(Source *src, Slot *slot, unsigned char mode) {
    Record *rec;
    float offset;

    rec = (Record *)(D_80126BF0 + 0x8B2C0 + 0x148 * slot->next); slot->next++;
    rec->list = D_80126BF4;
    rec->kind = 1;
    rec->f0C = 0.0f;
    rec->f10 = 0.0f;
    rec->f14 = 0.0f;
    offset = 0.0f;
    if (src->type == 3 || src->type == 6 || src->type == 9) {
        offset = 1.0f;
    }
    if (mode == 1) {
        rec->scale = D_80080C68;
    } else {
        rec->scale = 1.0f;
    }
    func_80018F20(mode, slot->alpha, src->x, (src->y + offset) / rec->scale, 0.0f);
    DISPLAY_COMMAND(D_80126BF4++, 0xB8000000, 0);
}
