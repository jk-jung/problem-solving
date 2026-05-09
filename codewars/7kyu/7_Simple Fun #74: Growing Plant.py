def growing_plant(a, b, c):
    h = 0
    for i in range(1, 10000000):
        h += a
        if h >= c:
            return i
        h -= b
