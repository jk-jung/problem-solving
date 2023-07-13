def mean_max(d, n):
    r = []
    for i in range(1, d + 1):
        r.append((i / d) ** n - sum(r))
    return sum((i + 1) * x for i, x in enumerate(r)) - (d + 1) / 2
