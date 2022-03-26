def thirt(n, m = -1):
    if n == m: return n
    r, x, j = 0, str(n), 0
    for i in range(len(x) - 1, -1, -1):
        t = int(x[i])
        r += [1, 10, 9, 12, 3, 4][j % 6]  * t
        j += 1
    return thirt(r, n)
