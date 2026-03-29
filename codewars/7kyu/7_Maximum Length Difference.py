def mxdiflg(a, b):
    r = -1
    for x in a:
        for y in b:
            r = max(r, abs(len(x) - len(y)))
    return r
