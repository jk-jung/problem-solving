def finding_k(v):
    r = -1
    for i in range(1, 1000):
        if len(set(x % i for x in v)) == 1: r = i
    return -1 if r == 999 else r
