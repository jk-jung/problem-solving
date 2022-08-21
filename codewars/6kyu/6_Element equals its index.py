def index_equals_value(v):
    s, e, r = 0, len(v) - 1, -1
    while s <= e:
        m = (s + e) // 2
        if v[m] == m:
            r = m
            e = m - 1
        elif v[m] < m: s = m + 1
        else: e = m - 1
    return r