def centroid(a) -> list[float]:
    n = len(a)
    r = [0 for _ in range(len(a[0]))]
    for y in a:
        for i in range(len(y)):
            r[i] += y[i] / n
    return r
