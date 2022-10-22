def order(v):
    n, m = len(v), len(v[0])
    v = sorted(sum(v, []))
    return [v[i:i + m] for i in range(0, len(v), m)]