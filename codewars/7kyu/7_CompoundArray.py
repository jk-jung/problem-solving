def compound_array(a, b):
    r = []
    for i in range(10000):
        if i < len(a): r.append(a[i])
        if i < len(b): r.append(b[i])
    return r
