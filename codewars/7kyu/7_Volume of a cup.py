from math import pi
def cup_volume(a, b, h):
    if a < b: a, b = b, a
    a /= 2
    b /= 2
    if a == b: return round(pi * a * a * h, 2)
    H = h / (a - b) * a
    def f(r, h): return r * r * h / 3 * pi
    return round(f(a, H) - f(b, H - h), 2)
