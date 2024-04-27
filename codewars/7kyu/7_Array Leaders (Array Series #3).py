def array_leaders(v):
    r = []
    for i, x in enumerate(v):
        if x > sum(v[i + 1:]):
            r.append(x)
    return r
