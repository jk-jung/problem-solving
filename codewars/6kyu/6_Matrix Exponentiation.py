def mul(a, b):
    m = len(a)
    r = [[0 for i in range(m)] for j in range(m)]
    for i in range(m):
        for j in range(m):
            for k in range(m):
                r[i][j] += a[i][k] * b[k][j]
    return r

def calc(v, n):
    m = len(v)
    r = [[1 if i == j else 0 for i in range(m)] for j in range(m)]

    while n:
        if n & 1: r = mul(r, v)
        v = mul(v, v)
        n >>= 1
    return r