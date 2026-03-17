def map_vector(v, a, b):
    b = list(b)
    r = a[2] / b[2]
    b[0] += (v[0] - a[0]) / r
    b[1] += (v[1] - a[1]) / r
    return tuple(b[:2])
