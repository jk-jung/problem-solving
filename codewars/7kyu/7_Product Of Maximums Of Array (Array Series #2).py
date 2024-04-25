def max_product(a, k):
    r = 1
    for x in sorted(a)[-k:]:
        r *= x
    return r
