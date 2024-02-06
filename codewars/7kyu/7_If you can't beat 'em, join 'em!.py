def cant_beat_so_join(v):
    r = []
    for x in sorted({sum(x) for x in v}, reverse=True):
        for y in v:
            if sum(y) == x:r.extend(y)
    return r
