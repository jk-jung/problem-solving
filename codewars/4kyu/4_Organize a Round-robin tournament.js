function buildMatchesTable(n) {
    let r = [], m = n >> 1
    let d = Array.from(Array(n + 1), () => new Array(n + 1))
    let d2 = Array.from(Array(n + 1), () => new Array(n + 1))

    let go = (y, x) => {
        if (x == n) x = 0, y++
        if (y == n - 1) return true

        for (let i = 1; i < n; i++) {
            if (d2[y][i] == 1) continue
            for (let j = i + 1; j <= n; j++) {
                if (d2[y][j] == 1) continue
                if (d[i][j] == 1) continue

                d2[y][i] = d2[y][j] = d[i][j] = 1
                r.push([i, j])
                if (go(y, x + 2)) return true
                r.pop()
                d2[y][i] = d2[y][j] = d[i][j] = 0
            }
        }
        return false
    }
    go(0, 0)
    let rr = []
    for (let i = 0; i < n - 1; i++) rr.push(r.slice(i * m, i * m + m))
    return rr
}