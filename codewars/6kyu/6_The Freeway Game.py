def freeway_game(d, s, v):
    r = 0
    t = d / s

    for x, y in v:
        x /= 60
        z = d / y

        if x <= 0 and t < x + z: r += 1
        if x >= 0 and t > x + z: r -= 1

    return r
