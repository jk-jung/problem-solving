def reg_sum_hits(n, s):
    d = [0 for _ in range(n * s + 1)]
    d[0] = 1
    for _ in range(n):
        for i in range(n * s, -1, -1):
            if d[i] == 0: continue
            for k in range(1, s + 1):
                d[i + k] += d[i]
            d[i] = 0

    return [[i, x] for i, x in enumerate(d) if x]