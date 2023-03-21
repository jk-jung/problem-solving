def layers(n):
    r, c = 1, 1
    while n > r * r:
        c += 1
        r = c * 2 - 1
    return c
