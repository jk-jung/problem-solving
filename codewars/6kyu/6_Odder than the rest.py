def oddest(v):
    def f(a):
        r = 0
        while a % 2:
            r += 1
            a //= 2
            if a == -1: return 1 << 30
        return r
    if not v: return None
    m = max(f(x) for x in v)
    v = [x for x in v if f(x) == m]
    return v[0] if len(v) == 1 else None
