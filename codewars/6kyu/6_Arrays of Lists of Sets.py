from collections import defaultdict
def solve(arr):
    r = defaultdict(int)
    r2 = defaultdict(int)
    for i, x in enumerate(arr):
        k = tuple(sorted(set(x)))
        r[k] += i
        r2[k] += 1
    return sorted([r[k] for k, v in r2.items() if v >= 2])
