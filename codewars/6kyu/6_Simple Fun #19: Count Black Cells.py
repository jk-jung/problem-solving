from math import gcd
def count_black_cells(h, w):
    return w + h - 1 + gcd(h, w) - 1
