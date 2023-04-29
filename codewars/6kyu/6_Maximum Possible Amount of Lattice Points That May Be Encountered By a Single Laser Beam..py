from collections import Counter
from itertools import combinations
def max_encount_points(v):
    def f(x, y): return x[0] * y[1] == x[1] * y[0]
    s = {}
    for a, b in combinations(v, 2):
        dx = b[0] - a[0]
        dy = b[1] - a[1]
        def f(x): return (x[0] - a[0]) * dy == (x[1] - a[1]) * dx
        t = tuple(x for x in v if f(x))
        s[t] = len(t)
    return sorted(Counter(s.values()).items())[-1]
