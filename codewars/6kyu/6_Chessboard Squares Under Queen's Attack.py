def chessboard_squares_under_queen_attack(a,b):
    r = 0
    for i in range(a):
        x = min(i + 1, b)
        r += x * (x - 1)
    for i in range(b - 1):
        x = min(i + 1, a)
        r += x * (x - 1)
    r *= 2
    r += (a + b - 2) * a * b

    return r
