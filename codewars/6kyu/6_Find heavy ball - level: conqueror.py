def find_ball(scales):

    def f(v):
        if len(v) == 1: return v[0]
        n = len(v) // 2
        a, b = v[:n], v[n:]
        return f(a) if scales.get_weight(a, b) == -1 else f(b)
    return f(list(range(8)))
