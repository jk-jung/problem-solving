def finaldist_crazyrobot(moves, init_pos):
    x, y = 0, 0
    for a, b in moves:
        if a == 'R': x += b
        elif a == 'L': x -= b
        elif a == 'U': y += b
        else: y -= b
    return (x * x + y * y) ** .5
