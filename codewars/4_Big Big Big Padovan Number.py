def mul(a, b):
    n = len(a)
    r = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                r[i][j] += a[i][k] * b[k][j]
    return r


def padovan(n):
    if n <= 2:
        return 1
    n -= 3
    k = n % 3
    t = n // 3
    x = [[1, 1, 0], [0, 1, 1], [1, 1, 1]]
    r = [[1, 1, 0], [0, 1, 1], [1, 1, 1]]
    while t:
        if t % 2:
            r = mul(r, x)
        x = mul(x, x)
        t //= 2
    return sum(r[k])

