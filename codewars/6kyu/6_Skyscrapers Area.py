def surface_area(v):
    n, m = len(v), len(v[0])
    r = 0
    for i in range(n):
        for j in range(m):
            h = v[i][j]
            if not h: continue
            r += 2
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                x = j + dx
                y = i + dy

                if 0 <= x < m and 0 <= y < n:
                    r += max(0, h - v[y][x])
                else:
                    r += h
    return r
