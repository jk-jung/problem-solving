def min_path(v, x, y):
    ck = {}
    for i in range(y + 1):
        for j in range(x + 1):
            if i == 0 and j == 0: ck[(i, j)] = v[i][j]
            else: ck[(i, j)] = min(ck.get((i - 1, j), 1 << 30), ck.get((i, j - 1), 1 << 30)) + v[i][j]
    return ck[(y, x)]
