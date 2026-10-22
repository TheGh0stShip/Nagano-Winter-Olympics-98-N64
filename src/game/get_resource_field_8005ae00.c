typedef struct Resource {
    unsigned int first;
    unsigned int value;
} Resource;

extern Resource *D_8007C950;

unsigned int func_8005AE00(Resource *resource) {
    if (resource == 0) {
        resource = D_8007C950;
    }
    return resource->value;
}
