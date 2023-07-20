def descriptions(v):
    v.append(-100)
    r, c = 1, 0
    for i in range(1, len(v)):
        if v[i - 1] + 1 == v[i]:
            c += 1
        else:
            r *= 2 ** c
            c = 0
    return r
