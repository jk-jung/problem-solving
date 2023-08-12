def rot_pred(v):
    a, b = v[:v.index('S')][::-1], v[v.index('S') + 1:]
    if len(a) != len(b): return 'Not a Valid Entry'
    def f(t): return sum(x * (i + 1) for i, x in enumerate(t))
    if f(a) == f(b): return 'steady'
    return 'anti clockwise' if f(a) > f(b) else 'clockwise'
