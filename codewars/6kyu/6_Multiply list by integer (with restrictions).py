def multiply(n, l, org=None):
    if n < 0:
        n = -n
        l = list(map(lambda x: -x, l))

    r, t = list(map(lambda x: 0, l)), 1
    while n:
        if n & 1: r = list(map(lambda x: sum(x), zip(l, r)))
        n //= 2
        l = list(map(lambda x: sum(x), zip(l, l)))
    return r
