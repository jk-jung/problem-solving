from functools import cache

import sys

sys.setrecursionlimit(100000)


@cache
def f(n, k):
    if n == 0: return 1
    if k == 0:return f(n - 1, 1)
    return f(n - 1, 1) + f(n - 1, 0)

def zeros(n):
    if n == 1:return 2
    return f(n - 1, 1)
