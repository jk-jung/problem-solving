import numpy as np
def normalize(v, default=0):
    dim, sz = 0, 0
    def dfs(x, d=1):
        nonlocal dim, sz
        dim = max(dim, d)
        sz = max(sz, len(x))
        [dfs(y, d + 1) for y in x if type(y) == list]


    def make(dep, a, b):
        if dep == dim - 1:
            [a.append(x) for x in b]
        else:
            for i in range(sz):
                a.append([])
                if i < len(b): bb = b[i]
                else: bb = default
                if type(bb) == int: bb = [bb] * sz
                bb = (bb + [default] * sz)[:sz]

                make(dep + 1, a[-1], bb)

    r = []
    dfs(v)
    make(0, r, v)

    return r