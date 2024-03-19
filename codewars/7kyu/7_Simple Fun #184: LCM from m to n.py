from math import gcd

def mn_lcm(m, n):
    r = 1
    for i in range(min(m, n), max(m, n) + 1):
        r = r * i // gcd(r, i)
    return r
