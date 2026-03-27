import math


def quadratic(a, b, c):
    x1 = (-b - math.sqrt(b**2 - 4 * a * c)) / (2 * a)
    x2 = c / (a * x1)
    return x2
