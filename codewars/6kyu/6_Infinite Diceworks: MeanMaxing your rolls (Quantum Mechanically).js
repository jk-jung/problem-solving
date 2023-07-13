function comb(n, k) {
    // Implement the combination formula
    if (k > n) {
        return 0;
    }
    let res = 1;
    for (let i = 1; i <= k; i++) {
        res *= (n - i + 1) / i;
    }
    return res;
}

function meanMaxQM(d, n) {
    let r = [];
    for (let i = 0; i < d; i++) {
        r.push(comb(n + i, i) - r.reduce((a, b) => a + b, 0));
    }
    let sumR = r.reduce((a, b) => a + b, 0);
    let sumProduct = r.reduce((acc, val, i) => acc + (i + 1) * val, 0);
    return sumProduct / sumR - (d + 1) / 2;
}