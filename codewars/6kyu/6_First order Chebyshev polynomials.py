from functools import cache

@cache
def chebyshev(n, v):
    if n == 0: return 1
    if n == 1: return v
    return chebyshev(n - 1, v) * 2 * v - chebyshev(n - 2, v)
