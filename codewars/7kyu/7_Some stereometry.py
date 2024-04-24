import math

def stereometry(r, h):
    surface_area = 4 * math.pi * r ** 2
    R = math.sqrt(r ** 2 - h ** 2)
    area_circle = math.pi * R ** 2
    perimeter_circle = 2 * math.pi * R
    return round(surface_area, 3), round(area_circle, 3), round(perimeter_circle, 3)
