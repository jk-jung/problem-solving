def knapsack(cap, v):
    v = sorted(enumerate(v), key=lambda x: -x[1][1] / x[1][0])
    r = [0 for _ in range(len(v))]

    for i, x in v:
        r[i] = cap // x[0]
        cap %= x[0]

    return r
