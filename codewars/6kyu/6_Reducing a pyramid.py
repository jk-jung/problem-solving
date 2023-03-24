def reduce_pyramid(base):
    r, n, c = 0, len(base) - 1, 1
    for i, x in enumerate(base):
        r += x * c
        c *= (n - i)
        c //= (i + 1)
    return r
