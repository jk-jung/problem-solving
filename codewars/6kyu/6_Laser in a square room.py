import math
def laser_coord(h, a, l):
    x = math.cos(a * math.pi / 180) * l
    y = math.sin(a * math.pi / 180) * l + h
    def f(x): return 1 - x % 1 if x % 2 >= 1 else x % 1
    return (f(x), f(y))
