def min_unfairness(v, k):
    if k == 0: return 0
    v.sort()
    r = 1 << 30
    for i in range(k - 1, len(v)):
        r = min(r, v[i] - v[i - k + 1])
    return r
