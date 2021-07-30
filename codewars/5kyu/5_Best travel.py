def choose_best_sum(t, k, v):
    d = {(0, 0): 1}
    r = -1
    for i in range(len(v)):
        for a, b in list(d.keys()):
            if a + v[i] <= t and b + 1 <= k:
                if b + 1 == k: r = max(r, a + v[i])
                d[(a + v[i], b + 1)] = 1
    return r if r >= 0 else None
