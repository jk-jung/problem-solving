def beggars(v, n):
    if n == 0: return []
    r = [0 for _ in range(n)]
    for i in range(len(v)):
        r[i % n] += v[i]
    return r
