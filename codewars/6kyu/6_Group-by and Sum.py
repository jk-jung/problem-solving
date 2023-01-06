def group(vv, idx):
    r = {}
    for v in vv:
        k = tuple(v[i] for i in idx)
        t = [v[i] for i in range(len(v)) if i not in idx]
        if k in r:
            for i, x in enumerate(t):r[k][i] += x
        else: r[k] = t
    return r
