typedef struct Pfs {
    int status;
    void *queue;
    int channel;
    unsigned char id[32];
    unsigned char label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    unsigned char banks;
    unsigned char activebank;
} Pfs;

typedef union InodeUnit {
    struct {
        unsigned char bank;
        unsigned char page;
    } inode_t;
    unsigned short ipage;
} InodeUnit;

typedef struct Inode {
    InodeUnit inode_page[128];
} Inode;

extern unsigned short func_80054390(unsigned char *data, int length);
extern int func_8005F480(void *queue, int channel, unsigned short address, unsigned char *buffer);
extern int func_8005DE60(void *queue, int channel, unsigned short address, unsigned char *buffer, int force);
int func_8005507C(Pfs *pfs);

int func_80054C60(Pfs *pfs) {
    int k;
    unsigned char temp[32];
    int ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_8005507C(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    ret = func_8005F480(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        if (ret != 2) {
            return ret;
        }
        ret = func_8005F480(pfs->queue, pfs->channel, 1, temp);
        if (ret != 0) {
            return ret;
        }
    }
    for (k = 0; k < 32; k++) {
        if (pfs->id[k] != temp[k]) {
            return 2;
        }
    }
    return 0;
}

int func_80054D5C(Pfs *pfs, Inode *inode, unsigned char flag, unsigned char bank) {
    unsigned char sum;
    int j;
    int ret;
    int offset;
    unsigned char *addr;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_8005507C(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    offset = (bank > 0) ? 1 : pfs->inode_start_page;
    if (flag == 1) {
        inode->inode_page[0].inode_t.page =
            func_80054390((unsigned char *)&inode->inode_page[offset], (128 - offset) * 2);
    }
    for (j = 0; j < 8; j++) {
        addr = (unsigned char *)inode->inode_page + j * 32;
        if (flag == 1) {
            ret = func_8005DE60(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            ret = func_8005DE60(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, 0);
        } else {
            ret = func_8005F480(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == 0) {
        sum = func_80054390((unsigned char *)&inode->inode_page[offset], (128 - offset) * 2);
        if (sum != inode->inode_page[0].inode_t.page) {
            for (j = 0; j < 8; j++) {
                addr = (unsigned char *)inode->inode_page + j * 32;
                ret = func_8005F480(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr);
            }
            if (sum != inode->inode_page[0].inode_t.page) {
                return 3;
            }
            for (j = 0; j < 8; j++) {
                addr = (unsigned char *)inode->inode_page + j * 32;
                ret = func_8005DE60(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            }
        } else {
            for (j = 0; j < 8; j++) {
                addr = (unsigned char *)inode->inode_page + j * 32;
                ret = func_8005DE60(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, 0);
            }
        }
    }
    return 0;
}

int func_8005507C(Pfs *pfs) {
    unsigned char temp[32];
    int i;
    int ret = 0;

    for (i = 0; i < 32; i++) {
        temp[i] = pfs->activebank;
    }
    ret = func_8005DE60(pfs->queue, pfs->channel, 0x400, temp, 0);
    return ret;
}
