def processes(s, e, v):
    q = [(x[2], [x[0]]) for x in v if x[1] == s]
    vis = {x[0] for x in q}
    while len(q):
        m, lst = q.pop(0)
        if m == e: return lst
        nt = [(x[2], lst + [x[0]]) for x in v if x[1] == m and x[2] not in vis]
        vis |= {x[0] for x in nt}
        q += nt
    return []
