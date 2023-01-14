from math import lcm


def candies_to_buy(n):
    r = 1
    for i in range(1, n + 1): r = lcm(r, i)
    return r
