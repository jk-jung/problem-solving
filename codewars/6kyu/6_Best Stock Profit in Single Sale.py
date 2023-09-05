def max_profit(v):
    r, c = -(1 << 30), 1 << 30
    for x in v:
        r = max(r, x - c)
        c = min(c, x)
    return r
