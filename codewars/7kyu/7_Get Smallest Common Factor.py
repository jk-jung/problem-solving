from math import gcd
def scf (arr):
    g = gcd(*arr)
    for i in range(2, g + 1):
        if g % i == 0: return i
    return 1
