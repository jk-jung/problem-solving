def sixteen_circles(r):
    a = 3 ** .5
    b = 2 ** .5
    x = (a / b + 1) * r * b * 2 - 4 * r
    return round(x / 2, 2)
