def trouble(v, t):
    r = [v.pop(0)]
    for x in v:
        if r[-1] + x != t: r.append(x)
    return r
