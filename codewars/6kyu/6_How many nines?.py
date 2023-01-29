def nines(n):
    n, u, r = str(n), 1, 0
    n += '0'

    d = {}
    def go(i, rng, ck=False):
        if i == len(n) - 1: return int(ck)
        k = (i, rng, ck)
        if k in d: return d[k]
        r = 0
        for x in range(rng + 1):
            if x == 10: continue
            if x == rng:
                r += go(i + 1, int(n[i + 1]), ck or x == 9)
            else:
                r += go(i + 1, 10, ck or x == 9)
        d[k] = r
        return r
    return go(0, int(n[0]))
