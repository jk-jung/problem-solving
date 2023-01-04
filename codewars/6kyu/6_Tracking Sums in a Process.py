def track_sum(v):
    def f(v):
        r = []
        [r.append(x) for x in v if x not in r]
        return r
    def g(v):
        v = sorted(v, reverse=True)
        return [v[i - 1] - v[i] for i in range(1, len(v))]
    def t(v): return v

    a = []
    for x in (t, f, g, f):
        v = x(v)
        a.append(sum(v))
    return [a, v]
