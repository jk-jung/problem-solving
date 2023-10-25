from itertools import pairwise
def delta(v, n):
    if n == 0: return v
    return delta((y - x for x, y in pairwise(v)), n - 1)
