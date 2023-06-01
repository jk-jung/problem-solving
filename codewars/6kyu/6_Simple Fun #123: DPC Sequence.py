from math import lcm, gcd
def DPC_sequence(s):
    if s[0] != 'D': return -1
    r = 1
    for i, x in enumerate(s):
        if x == 'D': r = lcm(r, i + 1)
    for i, x in enumerate(s):
        if x == 'P' and gcd(r, i + 1) != 1: return -1
        if x == 'C' and (gcd(r, i + 1) == 1 or r % (i + 1) == 0) : return -1
    return r
