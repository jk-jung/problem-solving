from collections import Counter
from math import comb
def uniq_count(s):
    c = Counter(s.lower())
    n = len(s)
    r = 1
    for x in c.values():
        r *= comb(n, x)
        n -= x
    return r
