def remove_internal(t):
    v = set(sum([list(x) for x in t], []))
    r = []
    for x in v:
        l = [list(y) for y in t if x in y]
        tt = set(sum(l, []))

        if len(l) + 1 == len(tt):
            r.append(x)
    return v - set(r)
