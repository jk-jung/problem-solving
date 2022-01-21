def rotate_in_place(v):
    if not v: return v
    n, m = len(v), len(v[0])
    r = []
    for j in range(m):
        t = []
        for i in range(n - 1, -1, -1):
            t.append(v[i][j])
        r.append(t)
    for i in range(n):
        for j in range(m):
            v[i][j] = r[i][j]

    return v