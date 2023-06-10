def alternate_sort(v):
    a = sorted([x for x in v if x >= 0])
    b = sorted([x for x in v if x < 0])
    r = []
    while a or b:
        if b:r.append(b.pop())
        if a:r.append(a.pop(0))
    return r
