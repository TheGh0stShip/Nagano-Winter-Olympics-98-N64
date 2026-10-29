void func_80025DFC(double *a, double *b, double *c, double *n) {
    double pad[2];
    double x[3];
    double y[3];
    double z[3];
    unsigned char i;

    for (i = 0; i < 3; i++) {
        x[i] = a[i];
        y[i] = b[i];
        z[i] = c[i];
    }
    n[0] = (y[1] - y[0]) * (z[2] - z[1]) - (z[1] - z[0]) * (y[2] - y[1]);
    n[1] = (z[1] - z[0]) * (x[2] - x[1]) - (x[1] - x[0]) * (z[2] - z[1]);
    n[2] = (x[1] - x[0]) * (y[2] - y[1]) - (y[1] - y[0]) * (x[2] - x[1]);
    for (i = 0; i < 3; i++) {
        if ((n[i] <= 0.0) && (n[i] > -0.00001)) n[i] = 0;
    }
}
