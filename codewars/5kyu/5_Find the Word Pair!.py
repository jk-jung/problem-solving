def compound_match(w, target):
    s = ''
    ww = {}
    for i, x in enumerate(w):
        if x not in ww: ww[x] = i

    t = target[:]
    for x in target:
        s += x
        t = t[1:]
        if s in ww and t in ww:
            a = ww[s]
            b = ww[t]
            if a > b: s, t = t, s
            return [s, t, [a, b]]
    return