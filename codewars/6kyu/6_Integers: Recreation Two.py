def prod2sum(a, b, c, d):
    s = (a ** 2 + b ** 2) * (c ** 2 + d ** 2)
    v = [
        a * c + b * d,
        a * c - b * d,
        a * d + b * c,
        a * d - b * c,
        ]

    r = set()
    for x in v:
        if x < 0: continue
        t = s - x ** 2
        if t < 0: continue
        y = int(t ** .5)
        if x ** 2 + y ** 2 == s:
            r.add((min(x, y), max(x, y)))
    return sorted(list(map(list, r)))
