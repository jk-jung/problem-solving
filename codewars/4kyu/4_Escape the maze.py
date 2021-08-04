# Return the array of movements to execute to get out of the maze

def escape(maze):
    n = len(maze)
    m = len(maze[0])
    q = []

    ck = {}
    for i in range(n):
        for j in range(m):
            if maze[i][j] not in '# ':
                t = (i, j, '^>v<'.index(maze[i][j]))
                ck[t] = 1
                q.append((t, []))

    dx = [0, 1, 0, -1]  # ^>v<
    dy = [-1, 0, 1, 0]

    while len(q) > 0:
        key, r = q.pop(0)
        y, x, d = key

        if y == 0 or x == 0 or y == n - 1 or x == m - 1:
            return r

        for k in range(1, 4):
            nd = (d + k) % 4

            t = (y, x, nd)
            if t in ck: continue
            ck[t] = 1
            q.append(((y, x, nd), r + ['R'] * k))

        ny = y + dy[d]
        nx = x + dx[d]
        t = (ny, nx, d)
        if ny < 0 or nx < 0 or ny >= n or nx >= m or maze[ny][nx] != ' ': continue
        if t in ck: continue
        ck[t] = 1
        q.append(((ny, nx, d), r + ['F']))

    return []
