function findD(v) {
    const s = new Set(v);
    let n = v.length - 1
    for (let i = n; i >= 0; i--)
        for (let j = n; j >= 0; j--) if (i != j)
            for (let k = j + 1; k <= n; k++) if (i != k) {
                const t = v[i] - v[j] - v[k]
                if (t != v[i] && t != v[j] && t != v[k] && s.has(t)) return v[i]
            }
    return null
}