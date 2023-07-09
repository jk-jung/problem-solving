from itertools import combinations
def solve(v):
    v = set(v)
    r = 0
    for x, y in combinations(sorted(v), 2):
        if y + y - x in v: r += 1
    return r
