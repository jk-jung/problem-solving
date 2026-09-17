def phi(n):
    res, x, p = n, n, 2
    while p * p <= x:
        if x % p == 0:
            while x % p == 0:
                x //= p
            res -= res // p
        p += 1
    if x > 1:
        res -= res // x
    return res


def check(b, h, p):
    v = 1
    for _ in range(h):
        v = b**v
        if v >= p:
            return p
    return v


def tower(b, h, m):
    if m == 1:
        return 0
    if h == 0 or b == 1:
        return 1

    p = phi(m)
    e = check(b, h - 1, p)
    if e >= p:
        e = tower(b, h - 1, p) + p
    return pow(b, e, m)
