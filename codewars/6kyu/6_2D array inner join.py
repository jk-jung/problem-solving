def inner_join(a, b, ai, bi):
    r = []
    for x in a:
        for y in b:
            if x[ai] == y[bi] and x[ai] is not None:
                r.append(x + y)
    return r
