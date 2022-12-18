def find_height(c):
    r, x, n = 0, 1, 2
    while c >= x:
        c, r, x, n = c - x, r + 1, x + n, n + 1
    return r
