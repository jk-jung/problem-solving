from collections import Counter
from math import comb
def proc_arr(s):
    c = Counter(s)
    r, n = 1, len(s)
    for k, v in c.items():
        r *= comb(n, v)
        n -= v
    return [r, int(''.join(sorted(s))), int(''.join(reversed(sorted(s))))]
