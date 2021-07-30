function findChain(arr) {
    let r = [], vis = {}

    let dfs = (y, x, t) => {
        let dx = [1, 0, -1, 0]
        let dy = [0, 1, 0, -1]
        t.push([y, x])
        vis[[y, x]] = 1

        for (let k = 0; k < 4; k++) {
            let ny = y + dy[k]
            let nx = x + dx[k]

            if (ny < 0 || nx < 0 || nx > 9 || ny > 9 || arr[ny][nx] !== arr[y][x]) continue
            if (vis[[ny, nx]]) continue
            dfs(ny, nx, t)
        }
    }
    for (let i = 0; i < 10; i++) for (let j = 0; j < 10; j++) {
        if (vis[[i, j]] === undefined) {
            let t = []
            dfs(i, j, t)
            if (t.length > r.length) r = t
        }
    }
    return r.sort()
}