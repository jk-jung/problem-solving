def socialist_distribution(v, m):
    if sum(v) < m * len(v): return []
    t = 0
    for i, x in enumerate(v):
        if x < m:
            t += m - x
            v[i] = m
    for _ in range(t):
        v[v.index(max(v))] -= 1
    return v
