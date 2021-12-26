def knights(ranks, p, r):
    a = ranks[p:] + ranks[:p]
    s, e = 0, len(a) - 1

    while True:
        c = 0
        while s <= e and a[s] == r: s, c = s + 1, c + 1
        while s <= e and a[e] == r: e, c = e - 1, c + 1
        if c == 0: break
        r += c

    return e - s + 2
