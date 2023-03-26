def lru(n, v):
    r = [-1 for _ in range(n)]
    t = [-1 for _ in range(n)]
    for c, x in enumerate(v):
        if x not in r:
            if -1 in r:
                i = r.index(-1)
            else:
                i = min(range(n), key=lambda y: t[y])
        else:
            i = r.index(x)
        r[i] = x
        t[i] = c
    return r
