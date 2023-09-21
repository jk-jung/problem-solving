def addsup(a1, a2, a3):
    a3 = set(a3)
    r = []
    for x in a1:
        for y in a2:
            if x + y in a3:
                r.append([x, y, x + y])
    return r
