typedef struct PiHandle {
    unsigned char pad_00[0x0C];
    unsigned int base_address;
} PiHandle;

int func_8005E360(PiHandle *handle, unsigned int device_address,
                  unsigned int value) {
    register unsigned int status;

    while ((status = *(volatile unsigned int *)0xA4600010) & 3) {
    }
    *(volatile unsigned int *)(0xA0000000 |
                               (handle->base_address | device_address)) = value;
    return 0;
}
