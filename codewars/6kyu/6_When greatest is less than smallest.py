from math import lcm
def greatest(x, y, n):
    x = lcm(x, y)
    if x < n: return n // x * x
    return 0

def smallest(x, y, n):
    l = lcm(x, y)
    g = greatest(x, y, n)
    return  g + l + l if g + l == n else g + l