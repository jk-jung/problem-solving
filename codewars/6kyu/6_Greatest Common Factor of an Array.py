from math import gcd
def greatest_common_factor(v):
    g = 0
    for x in v: g = gcd(g, x)
    return g
