import numpy as np

mod = 12345787

def pw(x, y):
    r = np.eye(4, dtype=np.int64)
    while y:
        if y % 2: r = r @ x % mod
        x = x @ x % mod
        y //= 2
    return r

def two_by_n(n, k):
    if n == 1: return k
    if k == 1: return 0
    x = np.array([
        [k - 1, (k - 1) * (k - 2), 0, 0],
        [0, 0, k - 2, (k - 1) * (k - 2) + 1],
        [1, 0, 0, 0],
        [0, 1, 0, 0]
    ], dtype=np.int64)
    y = np.array([k - 1, 1, 1, 0], dtype=np.int64)
    z = np.array([k, k * (k - 1), 0, 0], dtype=np.int64)
    return np.dot(pw(x, n - 2) @ y % mod, z) % mod