def sort_array(v):
    t = sorted(x for x in v if x % 2)
    for i in range(len(v)):
        if v[i] % 2: v[i] = t.pop(0)
    return v