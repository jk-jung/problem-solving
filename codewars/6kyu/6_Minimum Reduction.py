def min_remove(v):
    v = sorted(v)
    r, e = 0, 0
    for i in range(len(v)):
        while e < len(v) and v[e] <= v[i] ** 2: e += 1
        r = max(r, e - i)
    return len(v) - r
