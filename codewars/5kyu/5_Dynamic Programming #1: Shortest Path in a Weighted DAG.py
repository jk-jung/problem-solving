def shortest(n, v):
    v.sort()
    d = [1e10 for _ in range(n)]
    d[0] = 0

    for x in v:
        s, e, w = x
        d[e] = min(d[e], d[s] + w)
    return d[n-1] if d[n-1] < 1e10 else -1