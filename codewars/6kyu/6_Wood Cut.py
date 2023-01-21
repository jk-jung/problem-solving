def wood_cut(woods, n):
    s, e, r = 0, max(woods), 0
    while s <= e:
        m = (s + e) // 2
        if m == 0 or sum(x // m for x in woods) >= n:
            s, r = m + 1, m
        else:
            e = m - 1
    return r
