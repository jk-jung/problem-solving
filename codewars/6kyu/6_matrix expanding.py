def expand(v, f):
    n = len(v)
    r = [[f for x in range(n * 2)] for y in range(n * 2)]

    m = n // 2
    for i in range(n):
        for j in range(n):
            r[i + m][j + m] = v[i][j]
    return r