def count_diamonds(v ,target):
    n = len(v)
    m = len(v[0])

    s = [[0 for _ in range(m)] for _ in range(n)]
    def ss(y, x):
        if y == -1 or x == -1: return 0
        return s[y][x]

    for i in range(n):
        for j in range(m):
            s[i][j] = ss(i-1, j) + ss(i, j-1) - ss(i-1, j-1) + v[i][j]

    r = []
    for i in range(n):
        for j in range(m):
            for y in range(i+1):
                for x in range(j+1):
                    k = ss(i, j) - ss(i, x-1) - ss(y-1, j) + ss(y-1, x-1)
                    if k == target:
                        r.append([
                            (i - y + 1) * (j - x + 1),
                            (y, x), (i, j)
                        ])

    if len(r) == 0: return []
    size = min(r)[0]
    r = [x[1:] for x in sorted(r) if x[0] == size]

    return r