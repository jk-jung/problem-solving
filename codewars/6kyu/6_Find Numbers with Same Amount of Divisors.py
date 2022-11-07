from functools import cache


@cache
def f(x):
    r, i = 0, 1
    while i * i <= x:
        if x % i == 0:
            r += 1
            if i * i != x: r += 1
        i += 1
    return r


def count_pairs_int(d, n_max):
    return sum(f(i) == f(i + d) for i in range(1, n_max - d))