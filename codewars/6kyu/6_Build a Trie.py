def build_trie(*words):
    r = {}
    def f(x, i=0, d=r):
        k = x[:i + 1]
        if k not in d: d[k] = None
        if len(x) > i + 1:
            if d[k] is None: d[k] = {}
            f(x, i + 1, d[k])

    [f(x) for x in words if x]
    return r