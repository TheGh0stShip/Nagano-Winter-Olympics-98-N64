void *func_8004F954(void **link) {
    void *current = *link;
    register void *next __asm__("$25");

    next = *(void **)current;
    *link = next;
    return current;
}
