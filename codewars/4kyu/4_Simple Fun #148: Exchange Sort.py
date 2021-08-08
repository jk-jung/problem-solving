def exchange_sort(s):
    d = [[0 for _ in range(3)] for _ in range(3)]
    e = sorted(s)

    for x, y in zip(e, s):
        if x != y: d[x - 9][y - 9] += 1

    r = 0
    rest = 0
    for x, y in [(0, 1), (0, 2), (1, 2)]:
        k = min(d[x][y], d[y][x])
        r += k
        d[x][y] -= k
        d[y][x] -= k
        rest += d[x][y] + d[y][x]

    return r + rest // 3 * 2
