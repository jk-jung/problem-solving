def string_func(v, x):
    v = list(v)
    n = len(v)

    d = [0 for _ in range(n)]
    t = ['' for _ in range(n)]
    s, e, k = 0, n - 1, 0
    while s <= e:
        d[e] = k
        if e != s: d[s] = k + 1
        s, e, k = s + 1, e - 1, k + 2

    for i in range(70):
        if x >> i & 1:
            for k in range(n): t[d[k]] = v[k]
            for k in range(n): v[k] = t[k]
        for k in range(n): t[k] = d[d[k]]
        for k in range(n): d[k] = t[k]

    return ''.join(v)