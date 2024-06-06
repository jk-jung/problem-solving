def reverse_invert(v):
    def f(x):
        if x < 0: return int(str(-x)[::-1])
        return -int(str(x)[::-1])
    return [f(x) for x in v if isinstance(x, int)]
