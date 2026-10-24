void func_8004F0B8(unsigned long long *quotient,
                   unsigned long long *remainder,
                   unsigned long long dividend,
                   unsigned short divisor) {
    *quotient = dividend / divisor;
    *remainder = dividend % divisor;
}
