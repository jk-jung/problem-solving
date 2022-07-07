def performant_smallest(v, n):
    d = [0 for _ in range(51)]
    for x in v:
        d[x] += 1

    for i in range(1, 51):
        d[i] = min(d[i], n)
        n -= d[i]

    r = []
    for x in v:
        if d[x] > 0:
            r.append(x)
            d[x] -= 1
    return r
