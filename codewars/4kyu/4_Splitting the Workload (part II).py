def splitlist(v):
    v = v[::]
    s = sum(v)
    d = [-1 for _ in range(s + 1)]

    d[0] = 0
    for x in v:
        if x == 0: continue
        for i in range(s, -1, -1):
            if d[i] != -1 and d[i + x] == -1:
                d[i + x] = i
    r = s
    for i in range(s + 1):
        if d[i] != -1 and abs(s - i - i) < abs(s - r - r):
            r = i
    t = []
    while r:
        t.append(r - d[r])
        r = d[r]
    [v.remove(x) for x in t]

    return v, t
