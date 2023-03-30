def inter(a1, a2, b1, b2):
    if a1 > a2: a1, a2 = a2, a1
    if b1 > b2: b1, b2 = b2, b1
    return min(a2, b2) >= max(a1, b1)

def robot_walk(a):
    d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    r = [(0, 0)]
    [r.append((r[-1][0] + d[i % 4][0] * k, r[-1][1] + d[i % 4][1] * k)) for i, k in enumerate(a)]
    seg = [(r[i - 1], r[i]) for i in range(1, len(r))]
    for i, x in enumerate(seg):
        for j, y in enumerate(seg):
            if x == y or abs(i - j) == 1:continue
            a = inter(*[t[0] for t in x], *[t[0] for t in y])
            b = inter(*[t[1] for t in x], *[t[1] for t in y])
            if a and b: return True
    return False
