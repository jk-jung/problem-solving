def getting_mad(v):
    v.sort()
    return min(abs(x- y) for x, y in zip(v, v[1:]))
