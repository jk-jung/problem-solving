def add_all(v):
    r = 0
    while len(v) > 1:
        v = sorted(v)
        t = v.pop(0) + v.pop(0)
        r += t
        v.append(t)
    return r
