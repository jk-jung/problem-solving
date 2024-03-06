def max_df(n: int) -> int:
    s, e = 0, n
    r = -1
    while s <= e:
        m = (s + e) // 2
        if m * (m + 1) // 2 < n:
            s = m + 1
            r = m
        else: e = m - 1
    return r