import math


def wallpaper(l, w, h):
    t = math.ceil((l * h + w * h) / 5.2 * 2 * 1.15)
    if l == 0 or w == 0 or h == 0:
        t = 0
    return numbers[t]
