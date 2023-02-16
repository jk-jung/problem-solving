def fish(v):
    v = sorted(v)
    r, s = 1, 0
    for x in map(int, v):
        if x <= r: s += x
        a, b = 0, 4
        for i in range(100):
            a += b
            b += 4
            if s >= a: r = i + 2
    return r
