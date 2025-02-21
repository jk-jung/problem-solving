function iccanobif(n) {
    if (n == 1) return [1]
    let r = [1, 1];
    while (r.length < n) {
        r.unshift(r[1] + r[0])
    }
    return r
}