def can_jump(v):
    d = [0 for i in range(len(v))]
    d[0] = 1
    for i in range(len(v) - 1):
        if v[i] and d[i]:
            n = i + v[i]
            if n >= len(v): return True
            for j in range(i, n + 1):d[j] = 1
    return False
