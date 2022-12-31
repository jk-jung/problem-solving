from math import comb

def transform(A, y):
    A, pos, r, cur = sorted(A), y - 1, 0, 0
    for x in A:
        while pos < x:
            pos += 1
            cur += comb(pos, y)
        r ^= cur
    return r
