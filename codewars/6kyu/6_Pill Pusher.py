def prescribe(d, a, b):
    r = 0
    for i in range(d // a + 1):
        t = a * i
        r = max(r, t + (d - t) // b * b)
    return r
