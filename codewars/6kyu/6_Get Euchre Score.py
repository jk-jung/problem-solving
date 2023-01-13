def update_score(s, t, a, v):
    if t == 1:
        c = len([x for x in v if x == 1])
        if c <= 2: return [s[0], s[1] + 2]
        if c in (3, 4): return [s[0] + 1, s[1]]
        if a: return [s[0] + 4, s[1]]
        return [s[0] + 2, s[1]]
    else:
        c = len([x for x in v if x == 2])
        if c <= 2: return [s[0] + 2, s[1]]
        if c in (3, 4): return [s[0], s[1] + 1]
        if a: return [s[0], s[1] + 4]
        return [s[0], s[1] + 2]
