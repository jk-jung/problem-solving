def matrix_mult(a, b):
    n = len(a)
    r = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                r[i][j] += a[i][k] * b[k][j]
    return r
