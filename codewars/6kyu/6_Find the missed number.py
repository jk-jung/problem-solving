from collections import Counter
from itertools import permutations

def find_number(s, e, st):
    a = Counter(''.join(str(x) for x in range(s, e + 1)))
    b = Counter(st)
    r = sorted(''.join(str(k) * (v - b[k]) for k, v in a.items()))

    if not r: return []
    r = {int(''.join(k))for k in permutations(r) if k[0] != '0'}
    return [x for x in r if s <= x <= e]
