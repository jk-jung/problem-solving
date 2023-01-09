def interval_insert (v, a):
    v, r = sorted(v + [a]), []
    for x in v:
        if r:
            y = r[-1]
            if min(y[1], x[1]) - max(x[0], y[0]) >= 0:
                r[-1] = (min(x[0], y[0]), max(x[1], y[1]))
            else: r.append(x)
        else: r.append(x)
    return r
