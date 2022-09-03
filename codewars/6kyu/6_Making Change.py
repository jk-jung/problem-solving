from collections import Counter


def make_change(n):
    r = Counter()
    for k, v in [('H', 50), ('Q', 25), ('D', 10), ('N', 5), ('P', 1)]:
        while n >= v:
            n -= v
            r[k] += 1
    return r
