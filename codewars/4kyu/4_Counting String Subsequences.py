def count_subsequences(a, b):
    n = len(b)
    m = len(a)

    d = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    d[0][0] = 1
    for i in range(1, n + 1):
        d[i][0] = 1
        for j in range(1, m + 1):
            d[i][j] = d[i - 1][j]
            if b[i - 1] == a[j - 1]: d[i][j] += d[i - 1][j - 1]

    return d[n][m]
