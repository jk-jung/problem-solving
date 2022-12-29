from queue import PriorityQueue


def to_mountain(v):
    n, m = len(v), len(v[0])
    used = {}
    q = PriorityQueue()
    for i in range(n):
        for j in range(m):
            q.put((-v[i][j], i, j))

    while not q.empty():
        t, y, x = q.get()
        if (y, x) in used: continue
        used[(y, x)] = 1

        tar = []
        for dy in [-1, 0, 1]:
            for dx in [-1, 0, 1]:
                ny = y + dy
                nx = x + dx
                if (dy or dx) and 0 <= ny < n and 0 <= nx < m:
                    tar.append((ny, nx))
        mm = max(v[ny][nx] for ny, nx in tar)
        if mm > v[y][x]:
            v[y][x] = mm - 1
        for ny, nx in tar:
            if (ny, nx) not in used and v[ny][nx] <= v[y][x]:
                q.put((-max(v[y][x] - 1, v[ny][nx]), ny, nx))
    return v