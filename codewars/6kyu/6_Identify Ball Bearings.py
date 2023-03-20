def identify_bb(v, w):
    n = len(v)
    vv = sum([[v[i]] * i for i in range(n)], [])
    return v[w(*vv) - n * (n - 1) * 5]
