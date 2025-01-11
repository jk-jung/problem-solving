from math import gcd
def get_jumps(x, y):
    return len(x) // gcd(len(x), y)