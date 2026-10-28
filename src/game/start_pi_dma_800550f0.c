typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef int s32;
typedef struct MesgHdr { u16 type; u8 priority; u8 status; void *returnQueue; } MesgHdr;
typedef struct IoMesg { MesgHdr hdr; void *dramAddress; u32 deviceAddress; u32 size; void *handle; } IoMesg;
extern s32 D_8007D9A0;
extern void *func_8005C4B0(void);
extern s32 func_8005ABD0(void *queue, void *message, s32 flag);
extern s32 func_8004E2A0(void *queue, void *message, s32 flag);

s32 func_800550F0(IoMesg *message, s32 priority, s32 direction,
                  u32 deviceAddress, void *dramAddress, u32 size, void *returnQueue) {
    register s32 result;
    if (!D_8007D9A0) return -1;
    if (direction == 0) message->hdr.type = 11;
    else message->hdr.type = 12;
    message->hdr.priority = priority;
    message->hdr.returnQueue = returnQueue;
    message->dramAddress = dramAddress;
    message->deviceAddress = deviceAddress;
    message->size = size;
    message->handle = 0;
    if (priority == 1) result = func_8005ABD0(func_8005C4B0(), message, 0);
    else result = func_8004E2A0(func_8005C4B0(), message, 0);
    return result;
}
