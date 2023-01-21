def penalty(v):
    def f(x): return (x + x[-1] * 100)[:100], -len(x)
    return ''.join(sorted(v, key=f))
