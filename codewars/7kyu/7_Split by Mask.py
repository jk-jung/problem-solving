def split_by_mask(a, b):
    r = []
    for x in b:
        r.append(a[:x])
        a = a[x:]
        if len(r[-1]) != x:
            return
    return None if a else r
