def bfs(g, s):
    d = {(s, 0): 0}
    q = [(s, 0)]

    while len(q) > 0:
        x = q.pop(0)

        for y in g.get(x[0], []):
            y = (y, x[1]^1)
            if y not in d:
                d[y] = d[x] + 1
                q.append(y)

    return d


def converge(g, u1, u2, u3):
    d = [
        bfs(g, u1),
        bfs(g, u2),
        bfs(g, u3),
    ]

    r = 1e10
    for x in g:
        for i in range(2):
            dis = max(t.get((x, i), 1e10) for t in d)
            r = min(r, dis)

    return r if r < 1e10 else None