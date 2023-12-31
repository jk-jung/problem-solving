from math import gcd
def final_attack_value(x,v):
    for y in v:
        x += y if y <= x else gcd(x, y)
    return x
