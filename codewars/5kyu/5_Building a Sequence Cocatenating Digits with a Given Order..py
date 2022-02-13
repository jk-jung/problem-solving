from itertools import product


def proc_seq(*v):
    v = [set(str(x)) for x in v]

    r = [0, 1e10, -1e10, 0]
    for t in product(*v):
        s = int(''.join(t))
        if len(str(s)) != len(t): continue
        r[0] += 1
        r[1] = min(r[1], s)
        r[2] = max(r[2], s)
        r[3] += s

    if r[0] == 1: r = [r[0], r[3]]
    return r
