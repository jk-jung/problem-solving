def split_workload(w):
    if not w: return None, None
    s, a = sum(w), 0
    r = (abs(s), 0)
    for i, x in enumerate(w):
        a += x
        s -= x
        r = min(r, (abs(s - a), i + 1))
    return r[1], r[0]