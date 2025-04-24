def pyramid(balls):
    r = 0
    while r + 1<= balls:
        r += 1
        balls -= r
    return r
