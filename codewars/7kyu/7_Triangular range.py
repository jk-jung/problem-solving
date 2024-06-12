def triangular_range(start, stop):
    s, i = 0, 0
    r = {}
    while s + i <= stop:
        s += i
        if s >= start:
            r[i] = s
        i += 1
    return r
