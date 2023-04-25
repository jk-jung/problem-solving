def is_efficient(x, y, t):
    s = 0
    for i in range(-1, 2):
        for j in range(-1, 2):
            a = x + i
            b = y + j
            if a >= 0 and b >= 0 and a < 20 and b < 20:
                s += float(FIELD[a][b])
    return s >= t
