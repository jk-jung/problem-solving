def shortest_time(v):
    v = sorted(v)
    r = 0
    while len(v):
        if len(v) <= 2:
            r += v[-1]
            v = []
        elif len(v) == 3:
            r += v[0] + v[-1]
            v.pop(-1)
        else:
            c1 = v[1] + v[0] + v[-1] + v[1]
            c2 = v[0] + v[0] + v[-1] + v[-2]
            if c1 <= c2:
                r += c1
                v.pop(-1)
                v.pop(-1)
            else:
                r += v[0] + v[-1]
                v.pop(-1)
    return r
