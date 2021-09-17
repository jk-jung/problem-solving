def frogs_jumping(v):
    n = len(v)
    d = [(1e10, '') for _ in range(n)]
    d[0] = (0, '')

    for i in range(1, n):
        if v[i] - v[i - 1] == 1: d[i] = min(d[i], (d[i - 1][0] + 1, d[i - 1][1] + '1'))
        if v[i] - v[i - 1] == 2: d[i] = min(d[i], (d[i - 1][0] + 1, d[i - 1][1] + '2'))
        if i > 1 and v[i] - v[i - 2] == 2: d[i] = min(d[i], (d[i - 2][0] + 1, d[i - 2][1] + '2'))
    return d[n - 1][1]
