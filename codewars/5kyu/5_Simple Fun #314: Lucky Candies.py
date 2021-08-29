def lucky_candies(v, k):
    d1 = [0 for _ in range(k)]
    d1[0] = 1
    for x in v:
        d2 = d1[:]
        for i in range(k):
            if d1[i] == 0: continue
            d2[(i + x) % k] = max(d2[(i + x) % k], d1[i] + x)
        d1 = d2

    return d1[0] - 1
