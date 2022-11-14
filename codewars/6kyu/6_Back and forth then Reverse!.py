def arrange(v):
    r = []
    s, e = 0, len(v) - 1
    while s <= e:
        if s % 2 == 0:
            r.append(v[s])
            if s != e: r.append(v[e])
        else:
            r.append(v[e])
            if s != e: r.append(v[s])
        s += 1
        e -= 1
    return r
