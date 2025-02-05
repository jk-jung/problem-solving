def pair_zeros(v):
    r, s = [], set()
    for x in v:
        if not x and x in s:
            s.remove(x)
        else:
            r.append(x)
            s.add(x)
    return r
