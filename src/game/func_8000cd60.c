typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Matrix {
    signed int words[4][4];
} Matrix;

typedef struct CameraKey {
    float eyeX;
    float eyeY;
    float eyeZ;
    float atX;
    float atY;
    float atZ;
    float fovy;
} CameraKey;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_8013356C;
extern int D_80133568;
extern unsigned char D_8006D310[];
extern void func_800520C0(Matrix *output, unsigned short *perspNorm, float fovy, float aspect,
                          float near, float far, float scale);
extern void func_80052DD8(Matrix *output, float eyeX, float eyeY, float eyeZ, float atX,
                          float atY, float atZ, float upX, float upY, float upZ);
extern void func_800529C8(Matrix *output);

void func_8000CD60(Matrix *mtx, CameraKey *keys, int index, float t) {
    CameraKey *next;
    unsigned short perspNorm;
    float eyeX;
    float eyeY;
    float eyeZ;
    float atX;
    float atY;
    float atZ;
    float fovy;

    keys += index;
    next = keys + 1;
    if (D_80133568 == 1) {
        next = keys;
    }
    eyeX = keys->eyeX + (next->eyeX - keys->eyeX) * t;
    eyeY = keys->eyeY + (next->eyeY - keys->eyeY) * t;
    eyeZ = keys->eyeZ + (next->eyeZ - keys->eyeZ) * t;
    atX = keys->atX + (next->atX - keys->atX) * t;
    atY = keys->atY + (next->atY - keys->atY) * t;
    atZ = keys->atZ + (next->atZ - keys->atZ) * t;
    fovy = keys->fovy + (next->fovy - keys->fovy) * t;
    DISPLAY_COMMAND(D_8013356C++, 0x03800010, (unsigned int)D_8006D310);
    func_800520C0(mtx, &perspNorm, fovy, 4.0f / 3.0f, 1.0f, 1000.0f, 1.0f);
    DISPLAY_COMMAND(D_8013356C++, 0xBC00000E, perspNorm);
    DISPLAY_COMMAND(D_8013356C++, 0x01030040, (unsigned int)mtx);
    func_80052DD8(mtx + 1, eyeX, eyeY, eyeZ, atX, atY, atZ, 0.0f, 1.0f, 0.0f);
    DISPLAY_COMMAND(D_8013356C++, 0x01010040, (unsigned int)(mtx + 1));
    DISPLAY_COMMAND(D_8013356C++, 0xBC000404, 3);
    DISPLAY_COMMAND(D_8013356C++, 0xBC000C04, 3);
    DISPLAY_COMMAND(D_8013356C++, 0xBC001404, 0xFFFD);
    DISPLAY_COMMAND(D_8013356C++, 0xBC001C04, 0xFFFD);
    DISPLAY_COMMAND(D_8013356C++, 0xED020020, 0x004E03A0);
    func_800529C8(mtx + 2);
    DISPLAY_COMMAND(D_8013356C++, 0x01020040, (unsigned int)(mtx + 2));
}
