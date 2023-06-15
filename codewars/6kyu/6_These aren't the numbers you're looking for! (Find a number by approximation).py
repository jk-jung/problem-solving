def find_number(f):
    s, e = 0, 100
    for _ in range(100):
        m = (s + e) / 2
        if f(m) == 1: e = m
        else: s = m
    return s
