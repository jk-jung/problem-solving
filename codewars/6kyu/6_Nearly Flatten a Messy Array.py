def near_flatten(d):
    r = []
    def f(v):
        print(v)
        if isinstance(v[0], int): r.append(v)
        else: [f(x) for x in v]
    f(d)
    return sorted(r)
