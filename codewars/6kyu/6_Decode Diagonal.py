def get_diagonale_code(g):
    r, y, x, d, g = '', 0, 0, 1, g.split('\n')
    try:
        while True:
            r += g[y][x]
            if y + d >= len(g): d = -1
            if y + d < 0: d = 1
            y += d
            x += 2
    except: pass
    return r
