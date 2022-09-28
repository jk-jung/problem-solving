def greatest_distance(arr):
    r, c = 0, {}
    for i, x in enumerate(arr):
        if x in c: r = max(r, i - c[x])
        else: c[x] = i
    return r
