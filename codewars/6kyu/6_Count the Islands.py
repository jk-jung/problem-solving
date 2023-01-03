def count_islands(v):
    n, m = len(v), len(v[0])

    def f(i, j):
        v[i][j] = 0
        for a in [-1, 0, 1]:
            for b in [-1, 0, 1]:
                y, x = i + a, j + b
                if 0 <= y < n and 0 <= x < m and v[y][x] == 1:
                    f(y, x)
    r = 0
    for i in range(n):
        for j in range(m):
            if v[i][j]:
                r += 1
                f(i, j)
    return r