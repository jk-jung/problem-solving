import math


def missing_angle(h, a, o):
    def f(x):
        return round(x / 2 / math.pi * 360)

    if h == 0: h = (a ** 2 + o ** 2) ** .5
    if a == 0:
        return f(math.asin(o / h))
    else:
        return f(math.acos(a / h))
