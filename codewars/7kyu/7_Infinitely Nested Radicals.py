def fn(x):
    if x == 0: return 1
    r = 0
    for i in range(1000):
        r = (x + r) ** .5
    return r
