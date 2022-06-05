from math import gcd
def gcdi(x,y):
    return abs(gcd(x, y))

def lcmu(a, b):
    return abs(a * b // gcd(a, b))

def som(a, b):
    return a + b

def maxi(a, b):
    return max(a, b)

def mini(a, b):
    return min(a, b)

def oper_array(f, v, s):
    r = [s]
    [r.append(f(r[-1], x)) for x in v]
    return r[1:]
