import math

def nbr_of_laps(x, y):
    a = x * y // math.gcd(x, y)
    return (a // x, a // y)