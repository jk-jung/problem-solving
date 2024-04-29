def duplicates(a):
    y = set()
    r = []
    for x in a:
        if x not in y:y.add(x)
        elif x not in r:r.append(x)
    return r
