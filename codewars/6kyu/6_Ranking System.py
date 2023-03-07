def rankings(v):
    return [sorted(v, reverse=True).index(x) + 1 for x in v]