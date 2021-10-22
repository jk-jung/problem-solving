def height(n, m):
    r, f = 0, 1
    for i in range(n):
        f = f * (m - i) // (i + 1)
        r += f
    return r
