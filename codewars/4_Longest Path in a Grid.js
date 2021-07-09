function longestPath(str) {
    v = str.split('\n')
    let n = v.length
    let m = v[0].length
    let d = {}
    let dx = [1, 0, -1, 0, 1, 1, -1, -1]
    let dy = [0, 1, 0, -1, 1, -1, 1, -1]

    let dfs = (y, x) => {
        if ([y, x] in d) return d[[y, x]]

        let r = ''
        for (let i = 0; i < 8; i++) {
            let ny = y + dy[i]
            let nx = x + dx[i]
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] <= v[y][x]) continue
            r = fmin(r, dfs(ny, nx))
        }
        r = v[y][x] + r
        return d[[y, x]] = r
    }
    let fmin = (a, b) => {
        if (a.length === b.length) return a < b ? a : b
        return a.length > b.length ? a : b
    }

    let r = ''

    for (let i = 0; i < n; i++) for (let j = 0; j < m; j++) {
        r = fmin(r, dfs(i, j))
    }

    return r
}