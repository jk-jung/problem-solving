def shallowest_path(v):
    n = len(v)
    m = len(v[0])

    def bfs(limit):
        q, vis = [], {}
        for i in range(n):
            if v[i][0] <= limit:
                q.append((i, 0))
                vis[(i, 0)] = [(i, 0)]

        while len(q) > 0:
            y, x = q.pop(0)
            t = vis[(y, x)]

            if x == m - 1: return t

            for dy in [-1, 0, 1]:
                for dx in [-1, 0, 1]:
                    ny = y + dy
                    nx = x + dx
                    if ny < 0 or nx < 0 or ny >= n or nx >=m: continue
                    if v[ny][nx] > limit or (ny, nx) in vis: continue
                    q.append((ny, nx))
                    vis[(ny, nx)] = t + [(ny, nx)]
        return None

    mm = max(max(y) for y in v)

    for i in range(1, mm + 1):
        r = bfs(i)
        if r: return r
