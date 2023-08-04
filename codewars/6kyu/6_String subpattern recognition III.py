from functools import reduce
from collections import Counter
from math import gcd

def has_subpattern(s):
    c = Counter(s)
    g = reduce(gcd, c.values())
    return ''.join(sorted(k * (v // g) for k, v in c.items()))

