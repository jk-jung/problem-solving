def flatten(v):
    r = []
    for x in v:
        if isinstance(x, list):
            r.extend(x)
        else:
            r.append(x)
    return r
