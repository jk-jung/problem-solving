import math
p = math.pi
def ellipse(a, b):
    x = p * a * b
    y = p * (3 / 2 * (a + b) - (a * b) ** .5)
    return f'Area: %.1f, perimeter: %.1f' % (x, y)
    # your code