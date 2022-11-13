def is_possible(v, g):
    g -= v[0]
    v = v[1:]
    ck = set()

    def go(idx, st):
        if idx == len(v):
            return st == 0
        k = (idx, st)
        if k in ck: return False
        ck.add(k)
        return go(idx + 1, st + v[idx]) or go(idx + 1, st - v[idx])
    return go(0, g)
