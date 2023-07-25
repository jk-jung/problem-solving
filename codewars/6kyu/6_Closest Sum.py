from itertools import combinations
def closest_sum(v, n):
    r = 1 << 30
    for x in combinations(v, 3):
        if abs(n - r) > abs(n - sum(x)):
            r = sum(x)
    return r
