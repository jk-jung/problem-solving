function calculateSeriesProbabilities(N, p) {
    let m = Math.floor((N + 1) / 2)

    let calc = (p) => {
        let r = [], v = Math.pow(p, m)
        for (let i = 0; i < m; i++) {
            r.push(v)
            v *= (m + i) / (i + 1) * (1 - p)
        }
        return r
    }

    return [...calc(p), ...calc(1 - p).reverse()]
}