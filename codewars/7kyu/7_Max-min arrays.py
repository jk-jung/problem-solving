def solve(v):
    v.sort(reverse=True)
    r = []
    s, e = 0, len(v) - 1
    while s <= e:
        r.append(v[s])
        if s != e: r.append(v[e])
        s += 1
        e -= 1
    return r
