typedef struct {
    long long quot;
    long long rem;
} LongLongDiv;

LongLongDiv func_8005EF50(long long numerator, long long denominator) {
    LongLongDiv result;

    result.quot = numerator / denominator;
    result.rem = numerator - denominator * result.quot;
    if (result.quot < 0 && result.rem > 0) {
        result.quot += 1;
        result.rem -= denominator;
    }
    return result;
}
