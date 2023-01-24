def find_most_adjacent(g):
    n, m = len(g), len(g[0])

    seen = set()
    r = (-100, 0)

    def dfs(y, x):
        c = 1
        seen.add((y, x))
        for dy, dx in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
            ny = y + dy
            nx = x + dx
            if 0 <= ny < n and 0 <= nx < m and (ny, nx) not in seen and g[ny][nx] == g[y][x]:
                c += dfs(ny, nx)
        return c
    for i in range(n):
        for j in range(m):
            if (i, j) not in seen:
                r = max(r, (dfs(i, j), -g[i][j]))
    return (-r[1], r[0])