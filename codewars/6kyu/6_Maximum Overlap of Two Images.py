def max_overlap(a, b):
    n, m = len(a), len(a[0])
    r = 0
    for i in range(-n, n):
        for j in range(-m, m):
            t = 0
            for x in range(m):
                for y in range(n):
                    if i + y >= n or j + x >= m or i + y < 0 or j + x < 0: continue
                    t += a[i+y][j+x] == b[y][x] and b[y][x] == 1
                    r = max(r, t)
    return r
