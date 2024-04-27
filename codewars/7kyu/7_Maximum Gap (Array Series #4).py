def max_gap(v):
    v.sort()
    return max(y - x for x, y in zip(v, v[1:]))
