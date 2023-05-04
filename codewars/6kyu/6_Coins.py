from math import gcd
def coins(a, b):
    print(a, b, gcd(a, b))
    if gcd(a, b) != 1: return -1
    if min(a, b) == 1: return -1
    return a * b - a - b
