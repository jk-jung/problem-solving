def mirrored_exponential_chunks(v):
    if len(v) == 0: return v
    n = len(v) // 2
    a = v[n::-1]
    b = v[n:]

    r = []
    if len(a) == len(b):
        r.append([a[0]])
        a = a[1:]
        b = b[1:]
    else:
        a = a[1:]

    m = 1
    while len(a) > 0:
        m *= 2
        r.append(b[:m])
        r = [a[:m][::-1]] + r

        a = a[m:]
        b = b[m:]

    return r
