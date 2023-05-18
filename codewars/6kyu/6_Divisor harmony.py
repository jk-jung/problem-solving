from functools import cache
from fractions import Fraction

@cache
def f(x):
    r = 0
    for i in range(1, x + 1):
        if x % i == 0: r += i
    return Fraction(r, x)


def solve(a,b):
    x, y = {}, {}
    r = 0
    for t in range(a, b):
        k = f(t)
        if k not in x:
            x[k] = t
        elif k not in y:
            y[k] = 1
            r += x[k]
    return r
