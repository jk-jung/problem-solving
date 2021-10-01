def best_place(v):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    n, m = len(v), len(v[0])
    d = {}

    def dfs(i, j, vis):
        if (i, j) in vis: return 0
        vis[(i, j)] = 1
        c = 1
        for k in range(4):
            y, x = i + dy[k], j + dx[k]
            if y < 0 or x < 0 or y == n or x == m or v[y][x] != ' ': continue
            c += dfs(y, x, vis)
        return c


    for i in range(n):
        for j in range(m):
            if v[i][j] != ' ': continue
            c = n - i
            if i > 0 and v[i-1][j] != ' ': c *= 0.99 ** (ord(v[i-1][j].lower()) - ord('a'))

            for k in range(4):
                y, x = i + dy[k], j + dx[k]
                if y < 0 or x < 0 or y == n or x == m or not v[y][x].isupper(): continue
                c *= 0.8
            d[(i, j)] = (dfs(i, j, {}) >= 4, -c, i)

    return sorted([(v, k) for k, v in d.items()])[0][1]