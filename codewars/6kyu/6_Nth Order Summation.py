def s(m, n):
    if m == 0: return 1
    r = n
    for i in range(1, m):
        r = r * (n + i) // (i + 1)
    return r
