def ideal_trader(v):
    r = 1
    for i in range(1, len(v)):
        if v[i - 1] < v[i]: r *= v[i] / v[i - 1]
    return r
