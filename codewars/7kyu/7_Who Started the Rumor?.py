def rumor_starter(a):
    r = set(a)
    for v in a.values():
        for x in v:
            r.discard(x)
    return sorted(list(r))
