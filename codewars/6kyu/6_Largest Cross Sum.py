def largest_cross_sum(v):
    n, m = len(v), len(v[0])
    rr = 0
    for i in range(n):
        for j in range(m):
            r = -v[i][j]
            for x in range(n):r += v[x][j]
            for y in range(m):r += v[i][y]

            rr = max(rr, r)
    return rr
