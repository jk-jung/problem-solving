def all_squared_pairs(n):
    r = []
    m = int(n ** .5)
    for i in range(m + 1):
        k = n - i * i
        t = int(k ** .5)
        if t < i: continue
        if t * t == k:
            r.append([i, t])

    return r
