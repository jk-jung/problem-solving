from math import gcd
from functools import reduce

def lcm(a, b): return a * b // gcd(a, b)

def survivor(v):
    g = reduce(gcd, v, 0)
    l = reduce(lcm, v, 1)

    if g != 1: return -1

    d = [0 for _ in range(100000)]
    d[0] = 1
    r = 0
    for i in range(1, 100000):
        for x in v:
            if i - x >= 0 and d[i - x]:
                d[i] = 1
                break

        if d[i] == 0: r = i

    return r