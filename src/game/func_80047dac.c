typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;

typedef struct {
    ALLink node;
    unsigned int startAddr;
    unsigned int lastFrame;
    char *ptr;
} AMDMABuffer;

typedef struct {
    unsigned char initialized;
    AMDMABuffer *firstUsed;
    AMDMABuffer *firstFree;
} AMDMAState;

extern AMDMAState D_8013CB08;
extern unsigned int D_80073680;
extern int D_80073684;
extern unsigned char D_8013CF10[][0x18];
extern unsigned char D_8013D510[];

extern void func_8004E720(ALLink *ln);
extern void func_8004E750(ALLink *ln, ALLink *to);
extern unsigned int func_800512C0(void *addr);
extern int func_800550F0(void *mb, int pri, int direction, unsigned int devAddr, void *dramAddr, unsigned int size, void *mq);

int func_80047DAC(int addr, int len, void *state) {
    void *foundBuffer;
    int delta, addrEnd, buffEnd;
    AMDMABuffer *dmaPtr, *lastDmaPtr;

    lastDmaPtr = 0;
    dmaPtr = D_8013CB08.firstUsed;
    addrEnd = addr + len;

    while (dmaPtr) {
        buffEnd = dmaPtr->startAddr + 0xA00;
        if (dmaPtr->startAddr > addr) {
            break;
        } else if (addrEnd <= buffEnd) {
            dmaPtr->lastFrame = D_80073680;
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return (int)func_800512C0(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (AMDMABuffer *)dmaPtr->node.next;
    }

    dmaPtr = D_8013CB08.firstFree;
    D_8013CB08.firstFree = (AMDMABuffer *)dmaPtr->node.next;
    func_8004E720((ALLink *)dmaPtr);

    if (lastDmaPtr) {
        func_8004E750((ALLink *)dmaPtr, (ALLink *)lastDmaPtr);
    } else if (D_8013CB08.firstUsed) {
        lastDmaPtr = D_8013CB08.firstUsed;
        D_8013CB08.firstUsed = dmaPtr;
        dmaPtr->node.next = (ALLink *)lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink *)dmaPtr;
    } else {
        D_8013CB08.firstUsed = dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 0x1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = D_80073680;
    func_800550F0(D_8013CF10[D_80073684++], 0, 0, (unsigned int)addr, foundBuffer, 0xA00, D_8013D510);

    return (int)func_800512C0(foundBuffer) + delta;
}
