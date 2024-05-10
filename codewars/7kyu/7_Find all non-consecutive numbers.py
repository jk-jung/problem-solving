def all_non_consecutive(v):
    t = v[0] - 1
    r = []
    for i, x in enumerate(v):
        if t + 1 != x:
            r.append({'i': i, 'n': x})
        t = x
    return r
