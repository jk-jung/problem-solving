def min_rook_distance(a, b):
    n = len(a)
    d = [[1 << 30 for i in range(1 << n)] for j in range(n)]

    for i, (x, y) in enumerate(a):
        dis = abs(x - b[0]) + abs(y - b[1])
        d[i][1 << i] = dis

    for st in range(1 << n):
        for p in range(n):
            if d[p][st] == (1 << 30):
                continue
            for q in range(n):
                if st >> q & 1:
                    continue
                nt = st | (1 << q)
                dis = abs(a[p][0] - a[q][0]) + abs(a[p][1] - a[q][1])
                d[q][nt] = min(d[q][nt], d[p][st] + dis)

    s = (1 << n) - 1
    return min(d[i][s] for i in range(n))
