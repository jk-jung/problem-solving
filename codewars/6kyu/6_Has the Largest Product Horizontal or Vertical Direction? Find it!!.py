def highest_prod(v):
    n, m = len(v), len(v[0])
    r = 0
    for i in range(n):
        for j in range(m):
            r1, r2 = v[i][j], v[i][j]
            for y in range(i + 1, n):
                r1 *= v[y][j]
                r = max(r, r1)
            for x in range(j + 1, m):
                r2 *= v[i][x]
                r = max(r, r2)
    return r