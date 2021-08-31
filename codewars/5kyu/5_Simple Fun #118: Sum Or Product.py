def sum_or_product(v):
    while len(v) > 1:
        v.sort()

        if v[0] == 1:
            if 2 in v: v[v.index(2)] += 1
            else: v[1] += 1
        else:
            v[1] *= v[0]
        v = v[1:]

    return v[0]