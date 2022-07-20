def split_integer(n, k):
    r = []
    for i in range(k):
        r.append(n // (k - i))
        n -= r[-1]
    return r
