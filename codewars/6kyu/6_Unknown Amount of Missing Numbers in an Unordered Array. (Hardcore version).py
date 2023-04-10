def miss_nums_finder(v):
    m = max(v)
    a = [True for _ in range(m)]
    for x in v: a[x-1] = False
    return [i + 1 for i, x in enumerate(a) if x]
