def group_in_10s(*v):
    if not v: return []
    d = [None for _ in range(max(v) // 10 + 1)]
    for x in sorted(v):
        k = x // 10
        if d[k] is None: d[k] = []
        d[k].append(x)
    return d
