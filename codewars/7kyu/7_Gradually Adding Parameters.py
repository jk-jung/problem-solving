def add(*v):
    r = 0
    for i in range(len(v)):
        r += v[i] * (i + 1)
    return r