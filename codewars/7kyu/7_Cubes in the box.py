def f(x, y, z):
    r = 0
    for i in range(min(x, y, z)):
        r += (x-i) * (y-i) * (z-i)
    return r