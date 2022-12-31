def same(a, b):
    def f(v): return sorted(sorted(x) for x in v)
    return f(a) == f(b)
