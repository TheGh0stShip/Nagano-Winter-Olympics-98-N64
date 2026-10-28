typedef struct Div {
    int quot;
    int rem;
} Div;

Div func_8005F050(int numer, int denom) {
    Div val;

    val.quot = numer / denom;
    val.rem = numer - denom * val.quot;
    if (val.quot < 0 && val.rem > 0) {
        val.quot++;
        val.rem -= denom;
    }
    return val;
}
