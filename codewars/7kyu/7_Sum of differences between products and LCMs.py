from math import lcm
def sum_differences_between_products_and_LCMs(v):
    return sum(x * y - lcm(x, y) for x, y in v)
