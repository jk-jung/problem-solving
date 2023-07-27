from math import log
def power_law(a, b, c):
    dx = b[0] / a[0]
    dy = b[1] / a[1]
    x = c / a[0]

    if dx == 1: return a[1]
    return round(a[1] * dy ** (log(x, dx)))
