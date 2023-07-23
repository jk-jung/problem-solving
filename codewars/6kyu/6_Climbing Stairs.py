def climbing_stairs(c):
    c = [0] + c
    d = [0 if i == 0 else 1 << 30 for i in range(len(c))]
    for i in range(1, len(c)):
        d[i] = min(d[i-1], d[i-2]) + c[i]
    return min(d[-1], d[-2])
