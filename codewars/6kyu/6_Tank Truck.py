import math
def tankvol(h, d, vt):
    r = d / 2
    if h > r:
        h = d - h
        ck = False
    else:
        ck = True

    y = r - h
    x = (r ** 2 - y ** 2) ** .5

    circle = r * r * math.pi
    ratio = (math.acos(y / r) / math.pi * circle - x * y) / circle
    ratio = ratio if ck else 1 - ratio
    return int(vt * ratio)