def unite_unique(*v):
    r = []
    for x in v:
        for y in x:
            if y not in r:
                r.append(y)
    return r
