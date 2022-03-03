def power(a):
    r = []
    for st in range(0, 1 << len(a)):
        r.append([x for i, x in enumerate(a) if st >> i & 1])
    return r