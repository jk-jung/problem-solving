function howManyPiecesOf(myjinxinsHeart) {
    let vv = myjinxinsHeart.split('\n')
    let v = []
    let n = vv.length
    let m = vv[0].length
    for (let i = 0; i < n; i++) vv[i] = ' '.repeat(n) + vv[i] + ' '.repeat(n)
    m = vv[0].length

    for (let i = 0; i < n; i++) {
        v.push([])
        for (let j = 0; j < m; j++) v[i].push(0)
    }


    let set = (y, x, c) => v[y][x] += c
    let crack = (y, x) => {
        let dx = [1, 1, -1, -1]
        let dy = [1, -1, 1, -1]
        set(y, x, 2)

        for (let i = 1; i < n; i++) {
            for (let k = 0; k < 4; k++) {
                let nx = x + dx[k] * i
                let ny = y + dy[k] * i

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue
                set(ny, nx, 1)
            }
        }
    }
    let dfs = (y, x) => {
        let dx = [1, 0, -1, 0, 1, 1, -1, -1]
        let dy = [0, 1, 0, -1, 1, -1, 1, -1]
        set(y, x, 1)

        for (let k = 0; k < 8; k++) {
            let nx = x + dx[k]
            let ny = y + dy[k]

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] !== 0) continue
            dfs(ny, nx)
        }
    }

    for (let i = 0; i < n; i++) for (let j = 0; j < m; j++) if (vv[i][j] === 'x')
        crack(i, j)

    for (let i = 0; i < n; i++) {
        let t = []
        for (let j = 0; j < m; j++) {
            if (v[i][j] === 0) {
                if (vv[i][j] === '*') t.push(0)
                else t.push(' ')
            } else {
                v[i][j]++
                while (v[i][j]--) t.push(' ')
            }
        }
        v[i] = t
    }

    let r = 0
    m = v[0].length
    for (let i = 0; i < n; i++) for (let j = 0; j < m; j++) if (v[i][j] === 0) {
        r++
        dfs(i, j)
    }

    return r
}