def indices(n, d):
    r = []
    def go(m, k, v):
        if k == 1:
            r.append(v + [m])
        else:
            for i in range(m + 1):
                go(m - i, k - 1, v + [i])

    go(d, n, [])
    return r