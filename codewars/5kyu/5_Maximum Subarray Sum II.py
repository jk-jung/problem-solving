def find_subarr_maxsum(v):
    n = len(v)
    r = [[], 0]
    for i in range(n):
        s, t = 0, []
        for j in range(i, n):
            t.append(v[j])
            s += v[j]

            if s > r[1]:
                r = [[t[:]], s]
            elif s == r[1]:
                r[0].append(t[:])
    if r[1] == 0: r[0] = []
    if len(r[0]) == 1: r[0] = r[0][0]
    return r
