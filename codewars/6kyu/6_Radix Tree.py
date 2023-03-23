def radix_tree(*w):
    w = set(w)
    r = {}
    def f(x, d):
        if x[0] not in d: d[x[0]] = {}
        if x[1:]: f(x[1:], d[x[0]])
    def g(d, cur=''):
        for k, v in d.items():
            g(v, cur + k)
        for k, v in list(d.items()):
            if len(v) == 1 and (cur + k) not in w:
                d[k + list(v.keys())[0]] = list(v.values())[0]
                del d[k]
    [f(x, r) for x in w if x]
    g(r)
    return r
