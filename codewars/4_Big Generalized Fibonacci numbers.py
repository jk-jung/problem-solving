import numpy as np


def generalized_fibonacchi(a, b, n):
    m = len(a)
    if n < m: return a[m]
    a.reverse()

    x = np.zeros((m, m), dtype='object')
    r = np.eye(m, dtype='object')
    a = np.array(a, dtype='object')
    for i in range(m):
        x[0][i] = b[i]
        if i > 0: x[i][i - 1] = 1

    n = n - m + 1
    while n:
        if n % 2 == 1: r = np.matmul(r, x)
        x = np.matmul(x, x)
        n //= 2
    return np.matmul(r, a)[0]
