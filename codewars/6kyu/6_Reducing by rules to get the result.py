def reduce_by_rules(v, f):
    r = v[0]
    for i, x in enumerate(v[1:]):
        r = f[i % len(f)](r, x)
    return r
