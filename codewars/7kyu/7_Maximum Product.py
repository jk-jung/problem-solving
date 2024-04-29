def adjacent_element_product(a):
    r = -(1 << 60)
    for x, y in zip(a, a[1:]):
        r = max(r, x * y)
    return r
