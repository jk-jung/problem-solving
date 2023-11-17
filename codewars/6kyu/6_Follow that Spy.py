def find_routes(v):
    s = ''
    for x in v:
        if all(x[0] != y[1] for y in v): s = x[0]
    r = [s]
    for _ in range(len(v)):
        for x in v:
            if x[0] == r[-1]:
                r.append(x[1])
    return ', '.join(r)
