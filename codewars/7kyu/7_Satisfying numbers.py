from math import gcd

def smallest(n):
    r = 1
    for x in range(2, n + 1):
        r *= x // gcd(r, x)
    return r
