def trace(v):
    if not v or set(len(x) for x in v) != {len(v)}: return
    return sum(v[i][i] for i in range(len(v)))
