def infected_zeroes(v):
    n = len(v)
    r = [1 << 30 for _ in range(n)]
    pos = -1
    for i in range(n):
        if v[i] == 0:
            pos = i
            r[i] = 0
        if v[i] and pos != -1: r[i] = min(r[i], i - pos)
    pos = -1
    for i in range(n - 1, -1, -1):
        if v[i] == 0: pos = i
        if v[i] and pos != -1: r[i] = min(r[i], pos - i)
    return max(r)
