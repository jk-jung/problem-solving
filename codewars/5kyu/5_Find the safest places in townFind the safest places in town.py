def advice(v, n):
    dis = {}
    q = []

    for y, x in v:
        if y < 0 or y >= n: continue
        if x < 0 or x >= n: continue
        q.append((y, x))
        dis[(y, x)] = 0


    if len(q) == 0:
        t = []
        for i in range(n):
            for j in range(n):
                t.append((i, j))
        return t

    while len(q) > 0:
        y, x = q.pop(0)

        for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ny = y + dy
            nx = x + dx

            if ny < 0 or ny >= n: continue
            if nx < 0 or nx >= n: continue
            if (ny, nx) in dis: continue
            dis[(ny, nx)] = dis[(y, x)] + 1
            q.append((ny, nx))

    d = max(1, max(dis.values()))
    return [x[0] for x in dis.items() if x[1] == d]