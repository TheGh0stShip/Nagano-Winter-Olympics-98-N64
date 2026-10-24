int func_800543EC(unsigned short *data, unsigned short *checksum,
                  unsigned short *inverted_checksum) {
    unsigned short value = 0;
    unsigned int offset;

    *checksum = *inverted_checksum = 0;
    for (offset = 0; offset < 28; offset += 2) {
        value = *(unsigned short *)((unsigned char *)data + offset);
        *checksum += value;
        *inverted_checksum += ~value;
    }
    return 0;
}
