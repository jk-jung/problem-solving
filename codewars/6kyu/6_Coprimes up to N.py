from math import gcd
def coprimes(n):
    r = [1]
    for i in range(2, n):
        if gcd(n, i) == 1:
            r.append(i)
    return r
