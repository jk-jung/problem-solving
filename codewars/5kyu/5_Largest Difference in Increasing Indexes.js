var largestDifference = function (v) {
    let n = v.length
    let r = 0
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (v[i] <= v[j]) r = Math.max(r, j - i);
        }
    }
    return r
};