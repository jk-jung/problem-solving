import math

def area_of_polygon_inside_circle(r, n):
    a = math.cos(math.pi / n) * r
    b = math.sin(math.pi / n) * r
    return round(a * b * n, 3)