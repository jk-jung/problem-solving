def find_ball(scales):
    a, b = [0, 1, 2], [3, 4, 5]
    w = scales.get_weight(a, b)
    if w == 0: return 6 if scales.get_weight([6], [7]) == -1 else 7
    def f(v):
        t = scales.get_weight([v[0]], [v[1]])
        if t == 0: return v[2]
        return v[0] if t == -1 else v[1]
    return f(a if w == -1 else b)