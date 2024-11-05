function squareUp(n) {
    let r = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (j >= n - i - 1)
                r.push((n - j));
            else r.push(0);
        }
    }
    return r
}