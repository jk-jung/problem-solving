def array_packing(a):
    r = 0
    for x in a[::-1]:
        r = (r << 8) | x
    return r
