long maximum_product(char n) {
    long r[105] = {};
    r[0] = 1;

    for(int k=2;k<=n;k++) {
        for(int i=n; i>=k;i--) {
            long t = r[i-k] * k;
            if(r[i] < t) r[i] = t;
        }
    }
    return r[n];
}