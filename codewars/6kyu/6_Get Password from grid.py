def get_password(g, directions):
    n, m = len(g), len(g[0])
    x, y = 0, 0
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'x':
                y, x = i, j
    r = ''
    for d in directions:
        if d.startswith('left'): x -= 1
        if d.startswith('right'): x += 1
        if d.startswith('up'): y -= 1
        if d.startswith('down'): y += 1
        if d[-1] == 'T': r += g[y][x]
    return r
