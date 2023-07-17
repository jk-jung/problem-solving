from itertools import chain, combinations
from math import lcm

def powerset(s):
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def gangs(s,k):
    s = [x for x in s if x <= k]
    return len({lcm(*x) for x in powerset(s) if lcm(*x) <= k})
