def fill_gaps(v):
    v = v[:]
    last = None
    for i, x in enumerate(v):
        if x is not None:
            if last == x:
                for j in range(i - 1, -1, -1):
                    if v[j] == x:break
                    v[j] = x
            last = x
    return v
