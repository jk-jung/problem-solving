from itertools import combinations
def sel_quot(v, m, t = None):
    r = []
    t = (0, 1) if t is None else [1] if t.lower() == 'odd' else [0]
    for x, y in combinations(sorted(set(v)), 2):
        if y % x == 0 and (k := y // x) >= m and k % 2 in t:
            r.append((k, (y, x)))
    return sorted(r)