def select_subarray(v):
    def f(i):
        a = sum(v) - v[i]
        r = 1
        for k in range(len(v)):
            if k != i: r *= v[k]
        if a == 0: return 1 << 3000
        return abs(r / a)

    y = min(map(f, range(len(v))))
    r = [[i, x] for i, x in enumerate(v) if f(i) == y]
    if len(r) == 1: r = r[0]
    return r
