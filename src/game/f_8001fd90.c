typedef struct Animator {
    unsigned char pad0[0x13C];
    unsigned short state;
    unsigned short mode;
    unsigned char pad140[2];
    unsigned short frame;
    float timer;
    float rate;
    unsigned short duration;
    unsigned short loops;
    unsigned short loop_limit;
} Animator;

extern unsigned char *D_80126BF0;

void func_8001FD90(Animator *anim, unsigned short duration, unsigned short frames) {
    if (D_80126BF0[0x7C8F0] == 0) {
        if (anim->duration == 0) {
            anim->duration = duration;
        }
        if (anim->mode != 0) {
            anim->timer = anim->timer + anim->rate * (float)1;
            if (anim->timer >= (unsigned int)anim->duration) {
                anim->frame++;
                anim->timer = 0.0f;
                if (anim->frame >= frames) {
                    if (anim->mode == 1) {
                        anim->frame--;
                        anim->state = 2;
                        anim->mode = 0;
                    } else if (anim->mode == 2) {
                        anim->frame = 0;
                        anim->loops++;
                        anim->state = 1;
                        if (anim->loops >= anim->loop_limit) {
                            anim->loops = 0;
                            anim->frame = frames;
                            anim->state = 2;
                            anim->mode = 0;
                        }
                    } else if (anim->mode == 3) {
                        anim->frame = 0;
                    }
                }
            }
        }
    }
}
