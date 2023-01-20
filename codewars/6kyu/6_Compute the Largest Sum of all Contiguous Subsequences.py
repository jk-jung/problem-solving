def largest_sum(v):
    m, s ,r = 0, 0, 0
    for x in v:
        s += x
        m = min(m, s)
        r = max(r, s - m)
    return r
