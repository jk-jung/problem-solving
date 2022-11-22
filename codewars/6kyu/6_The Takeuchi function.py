from functools import lru_cache


@lru_cache(maxsize=None)
def T(x, y, z):
    if x <= y:
        return y, 0
    else:
        a = T(x - 1, y, z)
        b = T(y - 1, z, x)
        c = T(z - 1, x, y)
        d = T(a[0], b[0], c[0])
        return d[0], d[1] + a[1] + b[1] + c[1] + 1


def solve(n):
    return sum(map(int, str(T(n, 0, n + 1)[1])))
