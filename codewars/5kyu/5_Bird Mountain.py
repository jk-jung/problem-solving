def peak_height(v):
    n, m = len(v), len(v[0])
    r = []
    for i in range(n):
        s = ''
        for j in range(m):
            ck = v[i][j] == '^'
            for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                y = i + dy
                x = j + dx
                if y < 0 or x < 0 or y == n or x == m or v[y][x] != '^':
                    ck = False
            s += ('^' if ck else ' ')
        r.append(s)

    if r == v: return 0
    return peak_height(r) + 1
