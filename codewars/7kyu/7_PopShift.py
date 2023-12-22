def pop_shift(s):
    s = list(s)
    r = ['', '']
    while len(s) >= 2:
        r[1] += s.pop(0)
        r[0] += s.pop(-1)
    return r + (s or [''])