import math

def fa(v):
    r = 0
    for i in range(2, len(v) + 1):
        r += math.factorial(i)
    return r
