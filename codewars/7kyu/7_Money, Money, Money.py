def calculate_years(a, b, c, d):
    r = 0
    while a < d:
        r += 1
        a += a * b * (1 - c)
    return r
