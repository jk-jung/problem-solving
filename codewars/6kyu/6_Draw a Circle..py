def circle(r):
    if r < 0: return ''
    if r == 0: return '\n'
    n = r * 2 - 1
    d = [[' ' for _ in range(n)] for _ in range(n)]

    m = r - 1
    for i in range(r):
        for j in range(r):
            if i < n and j < n and (i - m) ** 2 + (j - m) ** 2 < r * r:
                d[i][j] = '#'
                d[n - i - 1][j] = '#'
                d[n - i - 1][n - j - 1] = '#'
                d[i][n - j - 1] = '#'

    return '\n'.join(''.join(x) for x in d) + '\n'
