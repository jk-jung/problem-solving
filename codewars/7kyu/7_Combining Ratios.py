from math import gcd


def merge_ratios(a, b):
    x, y = map(int, a.split(":"))
    p, z = map(int, b.split(":"))
    x, y, z = x * p, y * p, z * y
    g = gcd(x, y, z)
    return f"{x//g}:{y//g}:{z//g}"
