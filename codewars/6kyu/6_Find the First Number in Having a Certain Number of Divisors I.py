from functools import cache

@cache
def f(x):
    r = 0
    for i in range(1, int(x ** .5) + 1):
        if x % i == 0:
            r += 1
            if x // i != i: r += 1
    return r

@cache
def find_min_num(n):
    for i in range(1, 1000000):
        if f(i) == n: return i
