from collections import Counter
from math import factorial
from functools import reduce
def count_perms(v):
    c = Counter(sum(v, []))
    r = factorial(sum(c.values()))
    for x in c.values():r //= factorial(x)
    return r
