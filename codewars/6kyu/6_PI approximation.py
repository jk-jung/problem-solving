from math import pi

def iter_pi(eps):
    i =1
    p = 4
    c = 1
    while abs(pi - p) > eps:
        if c < 0: c -= 2
        else: c += 2
        c = -c
        p += 4 / c
        i += 1
    return [i, round(p, 10)]