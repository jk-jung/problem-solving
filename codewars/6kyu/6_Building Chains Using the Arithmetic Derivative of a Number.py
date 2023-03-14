from functools import cache

@cache
def fac(x):
    from collections import Counter
    r = Counter()
    for i in range(2, int(x ** .5) + 1):
        while x % i == 0:
            r[i] += 1
            x //= i
    if x != 1:
        r[x] = 1
    return r

@cache
def go(n, kk, last=None):
    if n == 1: return [1] * kk
    if kk == 1: return [n]
    r = []
    f = fac(n)
    m = 0
    for k, v in f.items():
        t = n // (k ** v)
        m += t * v * (k ** (v - 1))
    return [n] + go(m, kk - 1, n)

def chain_arith_deriv(n, kk):
    r = go(n, kk)

    if r[1] == 1: return f"{n} is a prime number"
    return r