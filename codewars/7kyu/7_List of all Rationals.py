from math import gcd

def all_rationals():
    q = [(1, 1)]
    while True:
        x, y = q.pop(0)
        yield (x, y)
        q.append((x, x + y))
        q.append((x + y, y))
