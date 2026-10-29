typedef struct TextureObject {
    unsigned char pad0[4];
    unsigned short flags;
    unsigned short wrap;
    unsigned char pad8[4];
    short width;
    short height;
    float scroll_x;
    float scroll_y;
    unsigned char pad18[0x128];
    unsigned short *buffer;
} TextureObject;

extern short D_801365C0;
extern short D_801365C2;
extern void func_8001BE20(unsigned short *texels, unsigned short flags, short x, short y);

void func_8001B7B0(TextureObject *object, short columns, short rows) {
    short x;
    short y;
    short row;
    short col;
    unsigned int offset;
    unsigned short *texels;
    short start_x;
    short start_y;

    start_x = (int)object->scroll_x % object->width;
    start_y = (int)object->scroll_y % object->height;
    for (row = 0, y = start_y; y < 400; y += D_801365C2, row++) {
        if (row >= rows) {
            row = 0;
            if (object->wrap) {
                break;
            }
        }
        col = 0;
        for (x = start_x; x < 400; x += D_801365C0, col++) {
            if (col >= columns) {
                col = 0;
                if (object->wrap) {
                    break;
                }
            }
            offset = (row * columns + col) * D_801365C0 * D_801365C2;
            if (object->flags & 0x8000) {
                func_8001BE20(object->buffer + offset / 2 + 0x100, object->flags, x, y);
            } else {
                func_8001BE20(object->buffer + offset, object->flags, x, y);
            }
        }
    }
    if (object->wrap) {
        return;
    }
    row = 0;
    for (y = start_y; y < 400; y += D_801365C2, row++) {
        col = columns - 1;
        if (row >= rows) {
            row = 0;
        }
        for (x = start_x; x >= -D_801365C0; col--) {
            if (col < 0) {
                col = columns - 1;
            }
            x -= D_801365C0;
            offset = (row * columns + col) * D_801365C0 * D_801365C2;
            if (object->flags & 0x8000) {
                func_8001BE20(object->buffer + offset / 2 + 0x100, object->flags, x, y);
            } else {
                func_8001BE20(object->buffer + offset, object->flags, x, y);
            }
        }
    }
    row = rows - 1;
    for (y = start_y; y >= -400 - -object->height; row--) {
        if (row < 0) {
            row = rows - 1;
        }
        col = columns - 1;
        y -= D_801365C2;
        for (x = start_x; x >= -D_801365C0; col--) {
            if (col < 0) {
                col = columns - 1;
            }
            x -= D_801365C0;
            offset = (row * columns + col) * D_801365C0 * D_801365C2;
            if (object->flags & 0x8000) {
                func_8001BE20(object->buffer + offset / 2 + 0x100, object->flags, x, y);
            } else {
                func_8001BE20(object->buffer + offset, object->flags, x, y);
            }
        }
    }
    row = rows - 1;
    for (y = start_y; y >= -400 - -object->height; row--) {
        if (row < 0) {
            row = rows - 1;
        }
        col = 0;
        y -= D_801365C2;
        for (x = start_x; x < 400; x += D_801365C0, col++) {
            if (col >= columns) {
                col = 0;
            }
            offset = (row * columns + col) * D_801365C0 * D_801365C2;
            if (object->flags & 0x8000) {
                func_8001BE20(object->buffer + offset / 2 + 0x100, object->flags, x, y);
            } else {
                func_8001BE20(object->buffer + offset, object->flags, x, y);
            }
        }
    }
}
