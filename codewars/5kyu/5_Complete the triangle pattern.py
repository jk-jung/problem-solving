def make_triangle(s, e):
    n = e - s + 1
    m = 0
    while (m + 1) * m / 2 < n: m += 1
    if (m + 1) * m / 2 != n:
        return ''

    r = [[' ' for _ in range(m)] for _ in range(m)]
    y, x, k = -1, -1, 0
    d = [(1, 1), (0, -1), (-1, 0)]
    for i in range(s, e + 1):
        while True:
            ny, nx = y + d[k][0], x + d[k][1]
            print('   ', ny, nx)
            if ny < 0 or nx < 0 or ny == m or nx == m or r[ny][nx] != ' ':
                k = (k + 1) % 3
            else:
                break
        y, x = ny, nx
        r[y][x] = str(i % 10)

    return '\n'.join(' ' * (m - i - 1) + ' '.join(r[i][:i+1]) for i in range(m))