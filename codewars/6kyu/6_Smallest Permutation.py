from itertools import permutations

def min_permutation(n):
    ck = 1
    if n < 0:
        n = -n
        ck = -1

    r = n
    for x in permutations(str(n)):
        x = int(''.join(x))
        if len(str(x)) != len(str(n)): continue
        if abs(r) > abs(x):
            r = x
    return r * ck