function sort(v) {
    let n = v.length
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n - i; j++) {
            if (v[j] > v[j + 1]) {
                let t = v[j]
                v[j] = v[j + 1]
                v[j + 1] = t
            }
        }
    }
    return v
}