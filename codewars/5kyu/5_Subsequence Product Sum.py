mod = int(1e9 + 7)


def product_sum(a, m):
    n = len(a)
    d = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    d[n][0] = 1
    for i in range(n - 1, -1, -1):
        for j in range(0, m + 1):
            d[i][j] = d[i + 1][j]
            if j > 0: d[i][j] += d[i + 1][j - 1] * a[i]
            d[i][j] %= mod

    return d[0][m]
