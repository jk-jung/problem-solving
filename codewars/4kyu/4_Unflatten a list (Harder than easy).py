def unflatten(v, depth, rev=False):
    if depth == 0: return v

    r = []
    while len(v) > 0:
        x = v[-1] if rev else v[0]
        if type(x) == list:
            r.append(unflatten(x, 1, rev))
            v = v[:-1] if rev else v[1:]
        else:
            rv = x % len(v)
            if rv <= 2:
                r.append(x)
                v = v[:-1] if rev else v[1:]
            elif rv > 2:
                r.append(v[-rv:] if rev else v[:rv])
                v = v[:-rv] if rev else v[rv:]

    if rev: r.reverse()
    return unflatten(r, depth - 1, not rev)
