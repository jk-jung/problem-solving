function dfs(y, x, arr, group, group_id) {
    if (arr[y][x] === ' ') return 0
    if ([y, x] in group) return 0

    let dx = [1, 0, -1, 0]
    let dy = [0, 1, 0, -1]
    let s = 1
    group[[y, x]] = group_id

    for (let i = 0; i < 4; i++) {
        let ny = y + dy[i]
        let nx = x + dx[i]

        if (0 <= ny && ny < arr.length && 0 <= nx && nx < arr[ny].length && arr[ny][nx] !== '')
            s += dfs(ny, nx, arr, group, group_id)
    }
    return s
}

function bfs(y, x, arr, group, group_id, left, removed) {
    let q = [[y, x, left]]
    let dx = [1, 0, -1, 0, 1, 1, -1, -1]
    let dy = [0, 1, 0, -1, 1, -1, 1, -1]
    let vis = {}
    vis[[y, x]] = 1


    while (q.length > 0) {
        let [y, x, l] = q.shift()

        if ([y, x] in group && group_id !== group[[y, x]]) removed[[y, x]] = 1
        if (l === 0) continue

        for (let i = 0; i < 8; i++) {
            let ny = y + dy[i]
            let nx = x + dx[i]

            if (0 <= ny && ny < arr.length && 0 <= nx && nx < arr[ny].length && !([ny, nx] in vis)) {
                vis[[ny, nx]] = 1
                q.push([ny, nx, l - 1])
            }
        }
    }
}

function survivors(arr) {
    let group = {}
    let size = {}
    let m = Math.max(...arr.map(x => x.length))

    for (let i = 0; i < arr.length; i++) arr[i] += ' '.repeat(m - arr[i].length)

    for (let i = 0; i < arr.length; i++)
        for (let j = 0; j < arr[i].length; j++) {
            let g_id = Object.keys(group).length + 1
            size[g_id] = dfs(i, j, arr, group, g_id)
        }

    let removed = {}
    for (let i = 0; i < arr.length; i++)
        for (let j = 0; j < arr[i].length; j++) {
            if ([i, j] in group)
                bfs(i, j, arr, group, group[[i, j]], size[group[[i, j]]], removed)
        }

    let r = ''
    for (let i = 0; i < arr.length; i++)
        for (let j = 0; j < arr[i].length; j++)
            if (arr[i][j] !== ' ' && !([i, j] in removed)) r += arr[i][j]

    return r
}