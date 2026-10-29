typedef signed char s8;
typedef unsigned short u16;
typedef struct {
    s8 count;
    s8 pad1[3];
    u16 *next_masks;
    u16 *prev_masks;
    s8 cur;
} MenuNav;

extern u16 func_80005C48(void);
extern u16 func_80005CAC(void);

int func_80043838(MenuNav *nav) {
    u16 a;
    u16 b;
    s8 result = 0;
    a = func_80005C48();
    b = func_80005CAC();

    if (nav->cur < 0 || nav->cur >= nav->count) {
        nav->cur = 0;
    }
    if (nav->prev_masks[nav->cur] == 0 || (nav->prev_masks[nav->cur] & b) != 0) {
        if (a) {
            if ((nav->next_masks[nav->cur] & a) != 0) {
                nav->cur++;
                if (nav->cur >= nav->count) {
                    result = 1;
                }
            } else {
                result = -1;
            }
        }
    } else {
        result = -1;
    }
    return result;
}
