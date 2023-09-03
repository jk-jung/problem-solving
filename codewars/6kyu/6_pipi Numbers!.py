from functools import cache
import sys

sys.setrecursionlimit(20000)

@cache
def pipi(n):
    if n <= 1: return n
    k = n
    for i in range(1, n):
        k = k ** 2
        k -= pipi(i)
    return k ** 2
