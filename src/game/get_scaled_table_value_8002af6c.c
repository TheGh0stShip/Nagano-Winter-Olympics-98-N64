typedef struct Entry {
    unsigned short value;
    unsigned short pad[6];
} Entry;

typedef struct Scale {
    float value;
    float pad;
} Scale;

extern Entry D_8006D47C[][24];
extern Scale D_8006E474[];

float func_8002AF6C(unsigned short index, unsigned char table) {
    float result = (unsigned int)D_8006D47C[table][index].value;

    result *= D_8006E474[table].value;
    return result;
}
