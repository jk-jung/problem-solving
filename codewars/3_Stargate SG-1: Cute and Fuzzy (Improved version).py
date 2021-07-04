from queue import PriorityQueue


def trace(v, fr, p):
    while p:
        print(p)
        if v[p[0]][p[1]] == '.':
            v[p[0]] = v[p[0]][:p[1]] + 'P' + v[p[0]][p[1] + 1:]
        p = fr.get(p)
    return '\n'.join(v)


def wire_DHD_SG1(v):
    v = v.split('\n')
    n = len(v)
    m = len(v[0])

    q = PriorityQueue()
    d = {}
    fr = {}
    vis = {}
    dx = [0, 1, 0, -1, 1, 1, -1, -1]
    dy = [1, 0, -1, 0, 1, -1, 1, -1]
    dist = [1] * 4 + [2 ** .5] * 4

    for i in range(n):
        for j in range(m):
            if v[i][j] == 'S':
                q.put((0, i, j))
                d[(i, j)] = 0

    while not q.empty():
        dis, y, x = q.get()
        if v[y][x] == 'G': return trace(v, fr, (y, x))
        if (y, x) in vis: continue
        vis[(y, x)] = 1

        for i in range(8):
            ny = y + dy[i]
            nx = x + dx[i]
            ndis = dis + dist[i]

            if ny < 0 or nx < 0 or ny >= n or nx >= m or v[ny][nx] == 'X': continue

            if (ny, nx) not in d or d[(ny, nx)] > ndis:
                d[(ny, nx)] = ndis
                fr[(ny, nx)] = (y, x)
                q.put((ndis, ny, nx))

    return "Oh for crying out loud..."
