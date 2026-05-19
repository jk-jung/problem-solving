import math

def drink_water(h, r, wh, m, s):
    s = [0] + s
    rst = []
    v = 0
    for x in s:
        rst.append(x)
        v += x
        hh = v / (r * r * math.pi)
        if hh + m >= h - wh:
            return rst[1:]
    return "The crow is dead."