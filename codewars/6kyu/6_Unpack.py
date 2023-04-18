def unpack(l):
    r = []
    def f(v):
        if isinstance(v, (list, tuple, set)):
            [f(x) for x in v]
        elif isinstance(v, dict):
            [(f(x), f(y)) for x, y in v.items()]
        else:
            r.append(v)
    f(l)
    return r
