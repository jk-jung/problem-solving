def process(dist, v):
    n = len(v)
    st = [0 for _ in range(n)]

    while True:
        end = False
        for i in range(n): st[i] >>= 1
        for i in range(n):
            idx, t = v[i]
            if st[i] & 1: t.pop(0)
            else:
                j = (i + 1) % n
                st[j] |= 1 << (dist + t[0][1] - 1) // t[0][1]
                t.append(t.pop(0))
            if len(t) == 0: end = True
        if end: break
    v = [x for x in v if len(x[1]) > 0]
    if len(v) >= 2: return process(dist, v)
    return v


def queue_battle(dist,*v):
    v = [(i, list(enumerate(v[i]))) for i in range(len(v))]

    r = process(dist, v)
    if len(r) == 0: return (-1, ())
    return (r[0][0], tuple(x[0] for x in r[0][1]))