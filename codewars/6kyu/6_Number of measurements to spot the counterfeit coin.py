import sys
sys.setrecursionlimit(1000000)
from functools import cache

@cache
def f(n):
    if n <= 1: return 0
    r = 1 << 30
    x = n // 3
    for i in range(max(1, x - 5), min(x + 5,  n // 2 + 1)):
        r = min(r, max(f(i), f(n - i * 2)) + 1)
    return r

how_many_measurements = f
