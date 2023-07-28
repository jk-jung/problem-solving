from functools import cache

@cache
def f(x):
    return sum(i if x % i == 0 else 0 for i in range(1, x + 1))

@cache
def g(x):
    y = str(x)[::-1]
    if y[0] == '0' or int(y) == x: return 0
    return x if f(x) == f(int(y)) else 0

def equal_sigma1(n):
    return sum(g(x) for x in range(n + 1))