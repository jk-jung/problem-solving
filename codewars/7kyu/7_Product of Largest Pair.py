def max_product(a):
    p, q = -1, -1
    for x in a:
        if x > p: p, q = x, p
        elif x > q: q = x
    return p * q
