def flatten(*v):
    v = list(v)
    r = []
    for x in v:
        if type(x) == list:
            [r.append(y) for y in flatten(*x)]
        else: r.append(x)
    return r