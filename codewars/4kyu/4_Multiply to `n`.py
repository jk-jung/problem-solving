from math import comb
from collections import Counter

def multiply(n, k):
    m = int(n ** .5)
    c = Counter()
    for i in range(2, m + 1):
        while n % i == 0:
            n //= i
            c[i] += 1
    if n != 1: c[n] += 1

    r = 1
    for x in c.values():
        r *= comb(k + x - 1, k - 1)
    return r