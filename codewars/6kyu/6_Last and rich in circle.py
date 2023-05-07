def find_last(n, m):
    c = [[0, i + 1] for i in range(n)]
    i = 0
    while len(c) >= 2:
        n = len(c)
        nxt = (i + m - 1) % n
        for j in range(max(m, n)):
            c[i][0] += 1 if j < m else 2
            i = (i + 1) % n
        t = c.pop(nxt)
        if nxt == len(c): nxt = 0
        c[nxt][0] += t[0]
        i = nxt

    return (c[0][1], c[0][0])
