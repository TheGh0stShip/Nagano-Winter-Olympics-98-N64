typedef struct PiHandle {
    unsigned char pad_00[0x0C];
    unsigned int base_address;
} PiHandle;

int func_8005DBD0(PiHandle *handle, unsigned int device_address,
                  unsigned int *value) {
    register unsigned int status;

    while ((status = *(volatile unsigned int *)0xA4600010) & 3) {
    }
    *value = *(volatile unsigned int *)(handle->base_address | device_address |
                                       0xA0000000);
    return 0;
}
