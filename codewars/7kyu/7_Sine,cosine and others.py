def sctc(s):
    c = (1 - s ** 2) ** .5
    r = [s,  c]
    if c: r.append(s / c)
    if s: r.append(c / s)

    return [round(x, 2) for x in r]