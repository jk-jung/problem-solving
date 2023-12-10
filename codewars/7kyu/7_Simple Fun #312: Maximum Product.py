def maximum_product(v):
    r = -(1 << 60)
    ri = 0
    v = sorted(v)
    for i in range(len(v)):
        t = 1
        for j, y in enumerate(v):
            if i != j:t *= y
        if t > r:
            r = t
            ri = v[i]
    return ri
