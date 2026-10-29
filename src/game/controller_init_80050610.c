#include "controller.h"

#define USEC_TO_CYCLES(value) (((u64)(value) * D_8007C990) / 1000000ULL)

extern u64 D_8007C990;
extern s32 D_8007C970;
extern u8 D_80192A31;
extern u8 D_801929F0[];
extern u8 D_80192A30;
extern OSMesgQueue D_80192A58;
extern OSMesg D_80192A70;
extern OSTime osGetTime(void);
extern s32 osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval,
                      OSMesgQueue *queue, OSMesg message);
extern void __osSiCreateAccessQueue(void);

s32 func_80050610(OSMesgQueue *queue, u8 *pattern, OSContStatus *data) {
    OSMesg message;
    s32 result = 0;
    OSTime time;
    OSTimer timer;
    OSMesgQueue timerQueue;

    if (D_8007C970) {
        return 0;
    }
    D_8007C970 = 1;
    time = osGetTime();
    if (time < USEC_TO_CYCLES(500000)) {
        osCreateMesgQueue(&timerQueue, &message, 1);
        osSetTimer(&timer, USEC_TO_CYCLES(500000) - time, 0, &timerQueue, &message);
        osRecvMesg(&timerQueue, &message, 1);
    }
    D_80192A31 = 4;
    __osPackRequestData(0);
    result = __osSiRawStartDma(1, D_801929F0);
    osRecvMesg(queue, &message, 1);
    result = __osSiRawStartDma(0, D_801929F0);
    osRecvMesg(queue, &message, 1);
    __osContGetInitData(pattern, data);
    D_80192A30 = 0;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&D_80192A58, &D_80192A70, 1);
    return result;
}
