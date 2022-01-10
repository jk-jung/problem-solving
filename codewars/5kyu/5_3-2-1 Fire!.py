def laser(v):
    n, m = len(v), len(v[0])
    dii = '>v<^'
    di = {
        0: (1, 0),
        1: (0, 1),
        2: (-1, 0),
        3: (0, -1)
    }
    print(n,  m)
    q = []
    r, d, u = [], {}, {}
    for i in range(n):
        for j in range(m):
            if v[i][j] in dii:
                k = (i, j, dii.index(v[i][j]), 0)
                q.append(k)
                d[k] = 1

    while len(q):
        y, x, k, ck = q.pop(0)
        t = v[y][x]
        if 'A' <= t <= 'Z' and (y, x) not in u:
            r.append(t)
            u[(y, x)] = 1

        nxt = []

        if ck == 1 and t in dii:
            l = dii.index(t)
            if k != l and (k + l == 2 or k + l == 4):
                for dd in {0,1,2,3} - {k, l}:
                    nxt.append((y, x, dd, 0))
        elif ck == 1 and t == '\\':
            nxt = [(y, x, k ^ 1, 0)]
        elif ck == 1 and t == '/':
            nxt = [(y, x, 3 - k, 0)]
        else:
            nxt = [(y + di[k][1], x + di[k][0], k, 1)]

        for y, x, k, ck in nxt:
            if y < 0 or x < 0 or y == n or x == m or (y, x, k, ck) in d: continue
            d[(y, x, k, ck)]  = 1
            q.append((y, x, k, ck))

    return sorted(r)