def jump_to(n):
    n -= 1
    if n == 0: return 0
    s = 1
    e = n
    r = -1
    while s <= e:
        m = (s + e) // 2
        t = m * (m + 1) - m
        if t > n:e = m - 1
        else: s, r = m + 1, m
    n -= r * (r + 1) - r
    if n == 0: return r + r - 1
    return r + r - 1 + (n + r - 1) // r
