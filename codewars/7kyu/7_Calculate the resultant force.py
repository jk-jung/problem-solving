import math
def solution(a, b, c) :
    cc = c
    c = math.pi * c / 180
    x = a + b * math.cos(c)
    y = b * math.sin(c)

    r = math.atan(y/x) /math.pi * 180
    r = (180 + r) % 180

    if cc > 180: r -= 180

    return (x*x + y*y) ** .5, r
