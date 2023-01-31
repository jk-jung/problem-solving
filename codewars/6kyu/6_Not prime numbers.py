from functools import cache

@cache
def p(x): return any(x % y == 0 and x != y for y in range(2, int(x ** .5) + 2))


@cache
def f(x): return p(x) and all(y in '2357' for y in str(x))


def not_primes(a, b):
    return [x for x in range(a, b) if f(x)]
