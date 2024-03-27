def speed_limit(speed, signals):
    r = 0
    for x in signals:
        d = speed - x
        if 10 <= d < 20: r += 100
        if 20 <= d < 30: r += 250
        if 30 <= d: r += 500
    return r
