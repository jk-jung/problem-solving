from functools import cache


@cache
def f(x):
    if x == 1: return 0
    return (f(x // 2) if x % 2 == 0 else f(x * 3 + 1)) + 1

def longest_collatz(v):
    return max(v, key=f)
