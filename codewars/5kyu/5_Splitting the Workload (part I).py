def splitlist(v):
    n, ra, rb = len(v), v, []
    for i in range(1 << n):
        a, b = [], []
        [a.append(x) if i >> j & 1 else b.append(x) for j, x in enumerate(v)]
        if abs(sum(ra) - sum(rb)) > abs(sum(a) - sum(b)):
            ra, rb = a, b
    return ra, rb
