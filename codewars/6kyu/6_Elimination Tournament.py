def tourney(v):
    r = [v]
    while len(v) > 1:
        n = [max(v[i * 2], v[i * 2 + 1]) for i in range(len(v)//2)]
        if len(v) % 2: n = [v[-1]] + n
        r.append(n)
        v = n
    return r
