def magic_square(n):
    v = [[0 for _ in range(n)] for _ in range(n)]
    y, x = 0, n // 2
    for i in range(n * n):
        v[y][x] = i + 1
        if v[y - 1][(x + 1) % n] != 0:
            y = (y + 1) % n
        else: y, x = (y + n - 1) % n, (x + 1) % n
    return v
