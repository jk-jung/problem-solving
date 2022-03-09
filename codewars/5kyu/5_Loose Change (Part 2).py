def loose_change(v, m):
    d = [1e9 for _ in range(m + 1)]
    d[0] = 0
    for x in v:
        for i in range(x, m + 1):
            d[i] = min(d[i], d[i - x] + 1)
    return d[m]
