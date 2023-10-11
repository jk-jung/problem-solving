def check_grid(v, pos, n):
    x, y = pos
    return [
        sorted(v[y]),
        sorted(list(zip(*v))[x]),
        [v[y+i][x+i] for i in range(-200, 200) if y + i in range(n) and x + i in range(n)],
        [v[y+i][x-i] for i in range(-200, 200) if y + i in range(n) and x - i in range(n)],
    ]
