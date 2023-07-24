def perfect_team_of_minimal_size(n, c):
    r = 100
    for i in range(1, 1 << len(c)):
        t = set()
        d = 0
        for k in range(len(c)):
            if i >> k & 1:
                t |= set(c[k])
                d += 1
        if len(t) == n:r = min(r, d)
    return -1 if r == 100 else r + 1
