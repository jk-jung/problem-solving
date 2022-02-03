def find_sum(v):
    n = len(v)
    d = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(n):
        for j in range(n):
            d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]) + v[i][j]
    return d[n][n]
