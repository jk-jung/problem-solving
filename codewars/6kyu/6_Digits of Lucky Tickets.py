from math import comb
from functools import cache

def lucky_ticket(n):
    n //= 2
    r = 0
    for i in range(n):
        r += ((-1) ** i) * comb(2*n, i) * comb(11 * n - 1 - 10 * i, 2 *n - 1)
    return r
